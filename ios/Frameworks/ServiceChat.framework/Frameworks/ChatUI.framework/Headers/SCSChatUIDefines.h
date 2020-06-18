//
//  SCSChatDefines.h
//  ChatUI
//
//  Created by Michael Nachbaur on 2/24/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

@import ServiceCore.ServiceCommon.SCCDefines;

@class SCSPrechatObject;

SCS_EXTERN NSString * const SCSChatUILogIdentifier;

SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenActionChat;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatAgentAvatar;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenAttachmentClipIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenPreChatIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenDropdown;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatConnectingIcon;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatConnectingIconLarge;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenErrorLarge;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatBotFooterMenu;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenChatBotAvatar;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenRightArrow;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenActionChat")
SCS_EXTERN NSString * const kSCAppearanceChatIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatAgentAvatar")
SCS_EXTERN NSString * const kSCAppearanceChatAgentAvatar;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenAttachmentClipIcon")
SCS_EXTERN NSString * const kSCAppearanceAttachmentClipIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenPreChatIcon")
SCS_EXTERN NSString * const kSCAppearancePreChatIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenDropdown")
SCS_EXTERN NSString * const kSCAppearanceDropdown;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatConnectingIcon")
SCS_EXTERN NSString * const kSCAppearanceChatConnectingIcon;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenChatConnectingIconLarge")
SCS_EXTERN NSString * const kSCAppearanceChatConnectingIconLarge;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenErrorLarge")
SCS_EXTERN NSString * const kSCAppearanceErrorLarge;
