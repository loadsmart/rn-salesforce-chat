/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#ifndef __SCCDefines_h__
#define __SCCDefines_h__

#import <Foundation/Foundation.h>

#ifndef SCS_EXTERN
#ifdef __cplusplus
#define SCS_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SCS_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#ifndef NS_STRING_ENUM
#define NS_STRING_ENUM
#endif

#ifndef SCS_STRING_ENUM
#ifdef NS_TYPED_EXTENSIBLE_ENUM
#define SCS_EXTENSIBLE_STRING_ENUM NS_TYPED_EXTENSIBLE_ENUM
#define SCS_STRING_ENUM NS_TYPED_ENUM
#else
#define SCS_EXTENSIBLE_STRING_ENUM NS_EXTENSIBLE_STRING_ENUM
#define SCS_STRING_ENUM NS_STRING_ENUM
#endif
#endif

SCS_EXTERN NSString * const SCInterfaceStyleDefault;

/**
 Service feature area. This value can be `SCServiceTypeCases` or `SCServiceTypeKnowledge`.
 To learn how this is used for authentication, see [Authentication](./authentication.html).
 */
typedef NSString * SCServiceType SCS_STRING_ENUM;
SCS_EXTERN SCServiceType const SCServiceTypeCases;
SCS_EXTERN SCServiceType const SCServiceTypeKnowledge;

SCS_EXTERN NSString * const SCServiceCloudErrorDomain;
SCS_EXTERN NSString * const SCSOAuthInvalidSessionId;

// Error Domain
SCS_EXTERN NSString * const SCServiceErrorDomain;

/**
 * Possible error response codes when authenticating a user with your Salesforce org.
 */
typedef NS_ENUM(NSInteger, SCServiceErrorCode) {
    /**
     * Error condition when the session has expired or is invalid.
     */
    SCServiceUserSessionExpiredOrInvalidError = 401,
    /**
     * Error condition when the request to authenticate a user is refused by the server.
     */
    SCServiceUserRequestRefusedError = 403,
    /**
     * Error condition when the requested resource is not found on the server.
     */
    SCServiceUserResourceNotFoundError = 404,
    /**
     * Error condition when changing authentication settings results in an error.
     */
    SCServiceAuthenticationSettingsError = 1000,
};

/**
 Enumerated list of all configurable color tokens.
 To learn about color branding, see [Color Branding](./color-branding.html).
 */
typedef NSString * SCSAppearanceColorToken SCS_STRING_ENUM;

/// The brand primary color key, used for primary visual elements such as header colors.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandPrimary;

/// The brand secondary color key, used for action button colors.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandSecondary;

/// The color key typically used for icons or text being placed on a brand primary element.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandPrimaryInverted;

/// The color key used for actionable labels placed on brand secondary elements, such as action buttons and case submit buttons.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenBrandSecondaryInverted;

/// The navigation background color key.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenNavbarBackground;

/// The navigation bar text/button color key.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenNavbarInverted;

/// The primary contrast color key, used for the majority of text.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastPrimary;

/// The secondary contrast color key, used for sub category header text.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastSecondary;

/// The tertiary contrast color key is a calculated value used for unselected article backgrounds, footer backgrounds, and other secondary areas.
/// The value is calculated by SCSAppearanceContrastInvertedColor mixed with the SCSAppearanceContrastSecondaryColor with a 10% alpha applied.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastTertiary;

/// The quaternary contrast color key is a calculated value used for the tint coloring of accessory images.
/// This value is calculated by SCSAppearanceContrastInvertedColor mixed with the SCSAppearanceContrastSecondaryColor with a 50% alpha applied.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastQuaternary;

/// The contrast inverted color key, used for areas where high contrast are needed.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenContrastInverted;

/// The feedback primary color key, used to indicate success or good state.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenFeedbackPrimary;

/// The feedback secondary color key, used to indicate failure or bad state.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenFeedbackSecondary;

/// The feedback tertiary color key, used to for indication of non binary states.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenFeedbackTertiary;

/// The overlay background brand color key, used for semi-transparent overlay colors.
SCS_EXTERN SCSAppearanceColorToken const SCSAppearanceColorTokenOverlay;


#ifndef SCSAppearanceImageToken
/**
 Enumerated list of all configurable image tokens.
 */
typedef NSString * SCSAppearanceImageToken SCS_STRING_ENUM;
#endif

SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenClose;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenNoConnection;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenDone;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenBack;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenGenericError;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenWhiteBubble;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSubmitButtonPreviousArrow;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSubmitButtonNextArrow;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenMinimizeButton;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenError;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenNoAccess;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenCountBadgeBackground;
SCS_EXTERN SCSAppearanceImageToken const SCSAppearanceImageTokenSend;

/**
 Enumerated list of all configurable text label tokens.
 */
typedef NSString * SCSAppearanceLabelToken SCS_STRING_ENUM;

SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenArticleListTitle;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenArticleListSummary;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCategoryListTitle;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseFeedItemBody;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCategorySupportHomeTitle;

// Case branding tokens
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseListTitle;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseListDate;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseListSubTitle;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseDetailTitle;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseDetailSubtitle;
SCS_EXTERN SCSAppearanceLabelToken const SCSAppearanceLabelTokenCaseFeedTitle;

/**
 Enumerated list of all configurable action types.
 */
typedef NSString * SCSAction SCS_EXTENSIBLE_STRING_ENUM;

SCS_EXTERN SCSAction const SCSActionCaseInterface;
SCS_EXTERN SCSAction const SCSActionCasePublisher;
SCS_EXTERN SCSAction const SCSActionCaseList;
SCS_EXTERN SCSAction const SCSActionArticleSearch;
SCS_EXTERN SCSAction const SCSActionChatInterface;

/**
 Default sort index values for the built-in action items.
 */
typedef NS_ENUM(NSUInteger, SCSActionItemDefaultSort) {
    SCSActionItemDefaultSortArticleSearch = 10,
    SCSActionItemDefaultSortCaseInterface = 20,
    SCSActionItemDefaultSortChatInterface = 30,
    SCSActionItemDefaultSortSOSInterface  = 40,
};

// Notifications
SCS_EXTERN NSString * const SCSAuthenticationSettingsUpdatedNotification;

//Remote notification payload
SCS_EXTERN NSString * const SCSNotificationPayloadKeyCaseId;

// Live agent Logging
SCS_EXTERN NSString * const SCServiceCloudLoggingErrorDomain;

// Deprecated mappings
#ifndef SCS_API_DEPRECATED_WITH_REPLACEMENT
#define SCS_API_DEPRECATED_WITH_REPLACEMENT(__name) __API_DEPRECATED_WITH_REPLACEMENT(__name, ios(1.0,100.0))
#endif

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenBrandPrimary")
SCS_EXTERN NSString * const SCSAppearancePrimaryBrandColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenBrandSecondary")
SCS_EXTERN NSString * const SCSAppearanceSecondaryBrandColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenContrastPrimary")
SCS_EXTERN NSString * const SCSAppearanceContrastPrimaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenContrastSecondary")
SCS_EXTERN NSString * const SCSAppearanceContrastSecondaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenContrastInverted")
SCS_EXTERN NSString * const SCSAppearanceContrastInvertedColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenOverlay")
SCS_EXTERN NSString * const SCSAppearanceOverlayColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenFeedbackPrimary")
SCS_EXTERN NSString * const SCSAppearanceFeedbackPrimaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenFeedbackSecondary")
SCS_EXTERN NSString * const SCSAppearanceFeedbackSecondaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenFeedbackTertiary")
SCS_EXTERN NSString * const SCSAppearanceFeedbackTertiaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenNavbarBackground")
SCS_EXTERN NSString * const SCSAppearanceNavbarBackgroundColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenNavbarInverted")
SCS_EXTERN NSString * const SCSAppearanceNavbarInvertedColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenBrandPrimaryInverted")
SCS_EXTERN NSString * const SCSAppearancePrimaryBrandInvertedColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenBrandPrimaryInverted")
SCS_EXTERN NSString * const SCSAppearanceTitleTextColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenBrandSecondaryInverted")
SCS_EXTERN NSString * const SCSAppearanceSecondaryBrandInvertedColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenBrandSecondaryInverted")
SCS_EXTERN NSString * const SCSAppearanceBrandContrastColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenContrastTertiary")
SCS_EXTERN NSString * const SCSAppearanceContrastTertiaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceColorTokenContrastQuaternary")
SCS_EXTERN NSString * const SCSAppearanceContrastQuaternaryColor;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenClose")
SCS_EXTERN NSString * const kSCAppearanceImageClose;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenNoConnection")
SCS_EXTERN NSString * const kSCAppearanceNoConnection;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenDone")
SCS_EXTERN NSString * const kSCAppearanceDone;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenBack")
SCS_EXTERN NSString * const kSCAppearanceBack;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenGenericError")
SCS_EXTERN NSString * const kSCAppearanceGenericError;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenWhiteBubble")
SCS_EXTERN NSString * const kSCAppearanceWhiteBubble;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSubmitButtonPreviousArrow")
SCS_EXTERN NSString * const kSCAppearanceSubmitButtonPreviousArrow;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenSubmitButtonNextArrow")
SCS_EXTERN NSString * const kSCAppearanceSubmitButtonNextArrow;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenMinimizeButton")
SCS_EXTERN NSString * const kSCAppearanceMinimizeButtonImage;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenError")
SCS_EXTERN NSString * const kSCAppearanceError;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenNoAccess")
SCS_EXTERN NSString * const kSCAppearanceNoAccess;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceImageTokenCountBadgeBackground")
SCS_EXTERN NSString * const kSCAppearanceCountBadgeBackground;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenArticleListTitle")
SCS_EXTERN NSString * const SCAppearanceLabelArticleListTitleName;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenArticleListSummary")
SCS_EXTERN NSString * const SCAppearanceLabelArticleListSummaryName;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCategoryListTitle")
SCS_EXTERN NSString * const SCAppearanceLabelCategoryListTitleName;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseFeedItemBody")
SCS_EXTERN NSString * const SCAppearanceLabelCaseFeedItemBodyName;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseListTitle")
SCS_EXTERN NSString * const SCAppearanceLabelCaseListTitle;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseListDate")
SCS_EXTERN NSString * const SCAppearanceLabelCaseListDate;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseListSubTitle")
SCS_EXTERN NSString * const SCAppearanceLabelCaseListSubTitle;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseDetailTitle")
SCS_EXTERN NSString * const SCAppearanceLabelCaseDetailTitle;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseDetailSubtitle")
SCS_EXTERN NSString * const SCAppearanceLabelCaseDetailSubtitle;

SCS_API_DEPRECATED_WITH_REPLACEMENT("SCSAppearanceLabelTokenCaseFeedTitle")
SCS_EXTERN NSString * const SCAppearanceLabelCaseFeedTitle;

#endif

