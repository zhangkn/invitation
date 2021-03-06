//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

// #import "SharePreConfirmView.h"

@interface ForwardMessageLogicController
{
    id m_confirmView;	// 40 = 0x28

    NSMutableArray *m_msgList;	// 16 = 0x10
    NSArray *m_msgRecordOriginList;	// 24 = 0x18
    NSArray *m_toContacts;	// 32 = 0x20
    _Bool _bMutliContact;	// 64 = 0x40
    _Bool _bShowSendSuccessView;	// 65 = 0x41
    _Bool _bPresent;	// 66 = 0x42
    _Bool _bAnimation;	// 67 = 0x43
    _Bool _m_bFilterMyContact;	// 68 = 0x44
    int _m_commonSearchScene;	// 72 = 0x48
    unsigned int _m_uiAppMsgScene;	// 76 = 0x4c
    unsigned int _m_uiIDKeyScene;	// 80 = 0x50
    NSString *_confirmPlaceholder;	// 88 = 0x58
    NSString *_title;	// 96 = 0x60
    NSString *_fromContactUserName;	// 104 = 0x68
    NSArray *_toContacts;	// 112 = 0x70
}

@property(retain, nonatomic) NSArray *toContacts; // @synthesize toContacts=_toContacts;
@property(retain, nonatomic) NSString *fromContactUserName; // @synthesize fromContactUserName=_fromContactUserName;
@property(nonatomic) _Bool m_bFilterMyContact; // @synthesize m_bFilterMyContact=_m_bFilterMyContact;
@property(nonatomic) unsigned int m_uiIDKeyScene; // @synthesize m_uiIDKeyScene=_m_uiIDKeyScene;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) NSString *confirmPlaceholder; // @synthesize confirmPlaceholder=_confirmPlaceholder;
@property(nonatomic) _Bool bAnimation; // @synthesize bAnimation=_bAnimation;
@property(nonatomic) _Bool bPresent; // @synthesize bPresent=_bPresent;
@property(nonatomic) _Bool bShowSendSuccessView; // @synthesize bShowSendSuccessView=_bShowSendSuccessView;
@property(nonatomic) unsigned int m_uiAppMsgScene; // @synthesize m_uiAppMsgScene=_m_uiAppMsgScene;
@property(nonatomic) int m_commonSearchScene; // @synthesize m_commonSearchScene=_m_commonSearchScene;
@property(nonatomic) _Bool bMutliContact; // @synthesize bMutliContact=_bMutliContact;

- (void)OnMsgRevoked:(id)arg1 n64MsgId:(long long)arg2 SysMsg:(id)arg3;
- (_Bool)checkIfLargeFileMsgSendToLargeChatRoom:(id)arg1;
- (_Bool)showLargeFileMsgCannotSendToLargeChatRoomAlertIfNeed:(id)arg1 message:(id)arg2;
- (void)OnSelectSessionCancel:(id)arg1;
- (void)ForwardMsg:(id)arg1 ToContact:(id)arg2;
- (void)ForwardMsgList:(id)arg1 ToContact:(id)arg2;
- (void)reportImageMsgInfoWithMsgWrap:(id)arg1;
- (void)reportUrlMsgInfoWithMsgWrap:(id)arg1 actionRet:(_Bool)arg2;
- (void)OnSelectSessions:(id)arg1 SessionSelectController:(id)arg2;
- (void)showConfirmView:(id)arg1;
- (void)dismissViewController;
- (void)OnSharePreConfirmViewDidHide:(id)arg1;
- (void)OnSharePreConfirmViewStayAtWeChat:(id)arg1;
- (void)OnSharePreConfirmViewBackToApp:(id)arg1;
- (void)OnSharePreConfirmViewCancel:(id)arg1;
- (void)OnSharePreConfirmViewSend:(id)arg1;
- (void)showTips;
- (void)showContactSelectViewController;
- (void)forwardMsgList:(id)arg1 msgOriginList:(id)arg2 toContacts:(id)arg3;
- (void)forwardMsgList:(id)arg1 toContacts:(id)arg2;
- (void)forwardMsgList:(id)arg1;
- (void)forwardMessage:(id)arg1;
- (void)forwardRecordMessage:(id)arg1 msgList:(id)arg2 toContacts:(id)arg3;
- (void)reportViewControllerIDKey;
- (void)reportConfirmIDKey;
- (id)getMessages;
- (id)getToContacts;
- (void)clearData;
- (void)dealloc;
- (id)init;

@end

