//
//  SCSAuthenticationSettings.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-12-05.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Key values for the `SCSAuthenticationSettings` dictionary. When creating an
 `SCSAuthenticationSettings`, be sure to at least specify the required keys.
 
 - `SCSOAuth2JSONKeyAccessToken`: Access token (REQUIRED)
 - `SCSOAuth2JSONKeyInstanceUrl`: URL for your org instance (REQUIRED)
 - `SCSOAuth2JSONKeyRefreshToken`: Refresh token
 - `SCSOAuth2JSONKeyCommunityUrl`: URL for the community
 - `SCSOAuth2JSONKeyCommunityId`: ID for the community
 - `SCSOAuth2JSONKeyIdentityUrl`: URL for the identity
 
 */
typedef NSString * SCSOAuth2JSONKey SCS_STRING_ENUM;

SCS_EXTERN SCSOAuth2JSONKey const SCSOAuth2JSONKeyAccessToken; // Required
SCS_EXTERN SCSOAuth2JSONKey const SCSOAuth2JSONKeyRefreshToken;
SCS_EXTERN SCSOAuth2JSONKey const SCSOAuth2JSONKeyInstanceUrl; // Required
SCS_EXTERN SCSOAuth2JSONKey const SCSOAuth2JSONKeyIdentityUrl;
SCS_EXTERN SCSOAuth2JSONKey const SCSOAuth2JSONKeyCommunityUrl;
SCS_EXTERN SCSOAuth2JSONKey const SCSOAuth2JSONKeyCommunityId;

@class SFUserAccount;

/**
 Authentication settings for the Snap-ins SDK. This class is necessary if you
 want to use any of the SDK features in authenticated mode. You'll need to
 authenticate, for instance, if you want to access a knowledge base only
 accessible to logged in users, or if you want a user to view and manage their
 cases. Create an instance of this class using one of the provided initialization methods.
 
 You can either authenticate explicitly using
 `-[SCServiceCloud setAuthenticationSettings:forServiceType:completion:]`
 or you can authenticate on-demand by implementing
 `-[SCServiceCloudDelegate serviceCloud:shouldAuthenticateServiceType:completion:]`.
 
 To learn more about authentication, see [Authentication](../authentication.html).
 */
@interface SCSAuthenticationSettings : NSObject

/**
 Indicates whether these settings apply to a guest user who is not authenticated.
 */
@property (nonatomic, assign, readonly, getter=isGuestUser) BOOL guestUser;

/**
 Indicates whether the specified authentication settings are valid.
 */
@property (nonatomic, assign, readonly, getter=areSettingsValid) BOOL settingsValid;

/**
 Indicates whether the settings are being verified.
 */
@property (nonatomic, assign, readonly, getter=isVerifyingSettings) BOOL verifyingSettings;

/**
 The name of the user for these authentication settings.
 */
@property (nullable, nonatomic, strong, readonly) NSString *username;

/**
 Initializes this object as a guest user who is not authenticated.
 
 @param communityUrl The URL of the community that accepts guest users.
 */
- (instancetype)initWithGuestCommunityUrl:(nullable NSURL*)communityUrl NS_SWIFT_NAME(init(guest:));

/**
 Initializes this object using a dictionary of authentication settings.
 Refer to `SCSOAuth2JSONKey` for information about which dictionary keys are required.
 
 @param dictionary The dictionary of authentication settings. The keys are of type
 `SCSOAuth2JSONKey` and the values are strings.
 @param clientId The unique client ID for these authentication settings.
 
 @see `SCSOAuth2JSONKey`
 */
- (nullable instancetype)initWithOAuth2Dictionary:(NSDictionary<SCSOAuth2JSONKey,NSString*>*)dictionary clientId:(NSString*)clientId NS_SWIFT_NAME(init(oauth2:clientId:));

/**
 Initializes this object with a user account from the Salesforce Mobile SDK.
 This method automatically extracts all relevant information from the user account.
 
 @param account The mobile SDK user account from which to extract authentication settings.
 */
- (nullable instancetype)initWithMobileSDKAccount:(SFUserAccount*)account NS_SWIFT_NAME(init(mobileSDK:));

- (instancetype)init NS_UNAVAILABLE;

/**
 Verifies that the authentication settings are valid.
 
 @param completion Completion block that is called after the verification process.
 */
- (void)verifySettingsWithCompletion:(void(^)(BOOL success, NSError * _Nullable))completion;

@end

@interface SCSAuthenticationSettings (PushNotifications)

/**
 Indicates whether the account has been registered for notifications.
 */
@property (nonatomic, assign, readonly, getter = isRegisteredForPushNotifications) BOOL registeredForPushNotifications;

/**
 Indicates if the account is able to register for push notifications.
 
 @return `YES` if this account can support registering for push notifications.
 */
- (BOOL)supportsPushNotifications;

/**
 Registers the given device token for push notifications for the given account. If the current account is already registered, it automatically unregisters the previous token.
 
 @param deviceToken Device token supplied by the `-[UIApplicationDelegate application:didRegisterForRemoteNotificationsWithDeviceToken:]` method.
 @param completion Completion block that is called after the registration attempt.
 */
- (void)registerForPushNotifications:(NSData*)deviceToken completion:(nullable void(^)(BOOL success, NSError * _Nullable error))completion;

/**
 Unregisters the account from push notification support.
 
 @param completion Completion block that is called after the attempt to unregister.
 */
- (void)unregisterForPushNotifications:(nullable void(^)(BOOL success, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
