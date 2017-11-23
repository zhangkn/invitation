#import "src/WeChatRobot.h"
#import "src/KNHookClass/KNHook.h"
#import "src/include/FTSContactMgr.h"

#import "src/include/GroupMember.h"
// #import "src/include/CBaseContact.h"
%hook MicroMessengerAppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

	// 打印某个类的所有方法的，查看所有方法的执行顺序

	[KNHook hookClass:@"MultiSelectContactsViewController"];// CGroupMgr
    return %orig;
}
%end


%hook CMessageMgr

- (CMessageMgr *)init
{
	%log();
	CMessageMgr *ret = %orig;



    [self AddGroupMember];


	return ret;
}

/*拉（特定的）人进行所有的群     // Nov  3 17:33:58 iPhone WeChat[5579] <Warning>: KNHooklog :-(c)AddGroupMember:withMemberList:withDesp:(have 3 value)
*/
%new
- (void)AddGroupMember{

	//得到通讯录的信息
	FTSContactMgr *ftsContactMgr = [[[NSClassFromString(@"MMServiceCenter") defaultCenter] getService:NSClassFromString(@"FTSFacade")] ftsContactMgr];

        // [ftsContactMgr tryLoadContacts];//- (id)getGroupContacts;

        NSMutableDictionary *dicContact = [ftsContactMgr getContactDictionary];//getDicSourceContact

                NSMutableDictionary *getDicSourceContact = [ftsContactMgr getDicSourceContact];// m_uiType=2051 位群  m_uiType=7 好友 m_uiType=3 信用卡还款  m_uiType=1 腾讯自有通知
                	NSLog(@"getDicSourceContact :%@",[getDicSourceContact class]);// m_nsUsrName

                	                NSMutableArray *getArrSourceContact = [ftsContactMgr getArrSourceContact];// m_uiType=2051 位群  m_uiType=7 好友 m_uiType=3 信用卡还款  m_uiType=1 腾讯自有通知
                	NSLog(@"getArrSourceContact :%@",getArrSourceContact );// m_nsUsrName


                	CGroupMgr *groupMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("CGroupMgr")];
    // // NSMutableArray *array = [[TKRobotConfig sharedConfig] chatRoomSensitiveArray];
    // // [array enumerateObjectsUsingBlock:^(NSString *text, NSUInteger idx, BOOL * _Nonnull stop) {
    //     if([key containsString:@"z929118967"]) {



                	 // 获取群信息
    
    for (CContact *tmp in getArrSourceContact) {
        
        if ( [[tmp m_nsUsrName] hasSuffix:@"@chatroom"])
        {
            /* code */
            //拉人
            NSLog(@"tmp :%@",tmp );// m_nsUsrName
            
            
            
            for (CContact *key in getArrSourceContact) {
                
                if (!([tmp IsUserInChatRoom:key])){// 而且在白名单之内
                    NSLog(@"key :%@",key );// m_nsUsrName
                    
                 
                    
                    
                    GroupMember *groupMember = [[%c(GroupMember) alloc]init];
                    groupMember.m_nsMemberName = key.m_nsUsrName;
                    groupMember.m_uiMemberStatus = 0;
 
                    
                    [groupMgr AddGroupMember:tmp.m_nsUsrName withMemberList:@[groupMember] withDesp:nil];
                    
                    
                }
           
                
            }
  
            
        }
 
        
    }




}

- (void)MessageReturn:(unsigned int)arg1 MessageInfo:(NSDictionary *)info Event:(unsigned int)arg3 {
    %orig;
    NSLog(@"info:%@",info);
      

    CMessageWrap *wrap = [info objectForKey:@"18"];

    if (arg1 == 227) {
        NSDate *now = [NSDate date];
        NSTimeInterval nowSecond = now.timeIntervalSince1970;
        if (nowSecond - wrap.m_uiCreateTime > 60) {      // 若是1分钟前的消息，则不进行处理。
            return;
        }
        CContactMgr *contactMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("CContactMgr")];
        CContact *contact = [contactMgr getContactByName:wrap.m_nsFromUsr];
        if(wrap.m_uiMessageType == 1) {                                         // 收到文本消息
            if (contact.m_uiFriendScene == 0 && ![contact isChatroom]) {
                //        该消息为公众号
                return;
            }
            if (![contact isChatroom]) {                                        // 是否为群聊
                // [self autoReplyWithMessageWrap:wrap];                           // 自动回复个人消息
            } else {
                [self removeMemberWithMessageWrap:wrap];                        // 自动踢人
                // [self autoReplyChatRoomWithMessageWrap:wrap];                   // 自动回复群消息
            }
        } else if(wrap.m_uiMessageType == 10000) {                              // 收到群通知，eg:群邀请了好友；删除了好友。
            CContact *selfContact = [contactMgr getSelfContact];
            if([selfContact.m_nsUsrName isEqualToString:contact.m_nsOwner]) {   // 只有自己创建的群，才发送群欢迎语
                // [self welcomeJoinChatRoomWithMessageWrap:wrap];
            }
        }
    } else if (arg1 == 332) {                                                          // 收到添加好友消息
        // [self addAutoVerifyWithMessageInfo:info];
    }
}



%new
- (void)removeMemberWithMessageWrap:(CMessageWrap *)wrap {
    // BOOL chatRoomSensitiveEnable = [[TKRobotConfig sharedConfig] chatRoomSensitiveEnable];
    // if (!chatRoomSensitiveEnable) {
        // return;
    // }
    CGroupMgr *groupMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("CGroupMgr")];
    NSString *content = MSHookIvar<id>(wrap, "m_nsLastDisplayContent");
    // NSMutableArray *array = [[TKRobotConfig sharedConfig] chatRoomSensitiveArray];
    // [array enumerateObjectsUsingBlock:^(NSString *text, NSUInteger idx, BOOL * _Nonnull stop) {
        if([content containsString:@"推荐"]) {
            [groupMgr DeleteGroupMember:wrap.m_nsFromUsr withMemberList:@[wrap.m_nsRealChatUsr] scene:3074516140857229312];
    }
    // }];
}

%end