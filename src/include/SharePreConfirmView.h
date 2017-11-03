//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//


@interface SharePreConfirmView 

@property(retain, nonatomic) NSArray *m_arrToContacts; // @synthesize m_arrToContacts=_m_arrToContacts;
@property(retain, nonatomic) NSArray *m_arrMsgs; // @synthesize m_arrMsgs=_m_arrMsgs;
@property(retain, nonatomic) NSArray *m_msgRecordOriginList; // @synthesize m_msgRecordOriginList=_m_msgRecordOriginList;
@property(retain, nonatomic) NSString *title; // @synthesize title=_title;
@property(retain, nonatomic) NSString *successText; // @synthesize successText=_successText;
@property(nonatomic) unsigned long long singlePasteTextMaxLength; // @synthesize singlePasteTextMaxLength=_singlePasteTextMaxLength;
@property(nonatomic) _Bool hasInputSth; // @synthesize hasInputSth=_hasInputSth;
@property(nonatomic) _Bool isShowTextView; // @synthesize isShowTextView=_isShowTextView;
@property(retain, nonatomic) NSString *defaultShowText; // @synthesize defaultShowText=_defaultShowText;
@property(retain, nonatomic) NSString *defaultInputText; // @synthesize defaultInputText=_defaultInputText;
@property(retain, nonatomic) NSString *thumbImageUrl; // @synthesize thumbImageUrl=_thumbImageUrl;
@property(retain, nonatomic) NSString *source; // @synthesize source=_source;
@property(retain, nonatomic) UIImage *thumbImage; // @synthesize thumbImage=_thumbImage;
- (void)onMainWindowFrameChanged;
- (void)onTextView:(id)arg1 shouldChangeTextInRange:(struct _NSRange)arg2 replacementText:(id)arg3;
- (void)onLoadImageOK:(id)arg1;
- (void)onKickQuit;
- (id)getWebThumbImage;
- (void)hideKeyBoard;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)reloadExpressionButtonImage:(int)arg1;
- (void)onExpressionButtonClicked:(id)arg1;
- (void)onCancel;
- (void)onConfirm;
- (void)keyboardDidHide;
- (void)textViewTextDidChange;
- (void)keyboardWillShow;
- (void)MMGrowTextViewBeginEditing:(id)arg1;
- (void)MMGrowTextViewHeightDidChanged:(id)arg1;
- (void)didCommitEmptyText;
- (void)didCommitText:(id)arg1;
- (void)stayAtWeChat;
- (void)notifySendMsgOK;
- (void)showSendSuccessView;
- (void)resignInput;
- (void)becomeInput;
- (void)initInputController;
- (void)initEmoticonView;
- (void)initInputToolView;
- (void)initBottomButtons;
- (id)genNewBigButton;
- (id)genBackgroundView;
- (void)formImageContentView:(id)arg1;
- (void)formEmoticonContentView:(id)arg1;
- (void)formLinkContentView:(id)arg1;
- (void)formCardContentView:(id)arg1;
- (void)formRecordMsgContentView:(id)arg1;
- (void)formMultiMsgContentView;
- (void)formTextMsgContentView:(id)arg1;
- (void)formLocationMsgContentView:(id)arg1;
- (void)formNoteContentView:(id)arg1;
- (void)formContentViewByText:(id)arg1;
- (void)formContentViewByText:(id)arg1 lineNum:(long long)arg2;
- (void)initInputView;
- (void)initContentView;
- (void)initTitleView;
- (void)viewChatroomProfile:(id)arg1;
- (void)initChatroomProfileView:(id)arg1;
- (void)addBlurView:(id)arg1 atPoint:(struct CGPoint)arg2;
- (id)getBlurView;
- (void)onPressBackBtn;
- (void)rotateToCurrentOrientation;
- (void)rotateToOrientation:(long long)arg1;
- (void)layoutSubviewToOrientation:(long long)arg1;
- (double)getVisibleHeight;
- (id)getInputText;
- (void)hideView:(_Bool)arg1;
- (void)showView:(_Bool)arg1;
- (void)dealloc;
- (id)init;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)internalInit;
- (void)setHidden:(_Bool)arg1;
- (void)unregisterEvent;
- (void)registerEvent;
@end

