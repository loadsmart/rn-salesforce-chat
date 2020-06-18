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

#import <UIKit/UIKit.h>
#import "SCServiceCloudDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCServiceCloudDelegate;
@class SCAppearanceConfiguration;
@class SCSServiceConfiguration;
@class SCSAuthenticationSettings;

/**
 Shared singleton class used as the primary access point for the Snap-ins SDK.
 
 ### Overview
 
 This class gives you access to all the features of the SDK and allows you
 to configure or customize the SDK. Use the `+[SCServiceCloud sharedInstance]`
 class method to access the singleton for this class.
 
 You can access each of the SDK features with properties on this singleton:
 `SCServiceCloud.knowledge`, `SCServiceCloud.cases`, `SCServiceCloud.chatUI`,
 `SCServiceCloud.sos`.
 
 Specify your `SCServiceCloudDelegate` implementation using the
 `SCServiceCloud.delegate` property. With this delegate, you can respond
 to events and make decisions on behalf of the SDK.
 
 ### Configuration & Customization
 
 Specify the Knowledge and Case Management configuration settings using
 the `SCServiceCloud.serviceConfiguration` property.
 
 Customize the appearance of the interface (such as the colors, fonts, images, and strings)
 using the `SCServiceCloud.appearanceConfiguration` property. To learn more about
 SDK customizations, see [Color Branding](../color-branding.html) and
 [SDK Customizations in the Developer Guide](https://developer.salesforce.com/docs/atlas.en-us.service_sdk_ios.meta/service_sdk_ios/servicesdk_ui_customization.htm).
 
 ### Authentication & Notifications
 
 Knowledge and Case Management both have an option to authenticate users
 so that users can access information related to their user account or
 their user profile. To learn more about authentication, see [Authentication](../authentication.html).
 
 `SCServiceCloud` allows you to explicitly set the authentication settings using
 `-setAuthenticationSettings:forServiceType:completion:`. You can also check the
 authentication for a particular service using `-authenticationSettingsForServiceType:`.
 Refer to `SCSAuthenticationSettings` for the core class associated with authentication.
 
 Authenticated users can be notified using push notifications when there is activity
 on their cases. To learn more about notifications see [Push Notifications for Case Activity](https://developer.salesforce.com/docs/atlas.en-us.service_sdk_ios.meta/service_sdk_ios/cases_push_notification.htm).
 
 `SCServiceCloud` lets you determine whether the SDK can handle a remote push notification with
 `-notificationFromRemoteNotificationDictionary:`. If the notification
 can be handled by the SDK, pass it to the `-showInterfaceForNotification:` method.
 
 ### Action Buttons
 
 You can customize the action buttons used throughout the UI. You can override the look
 and the behavior of existing buttons, and you can create buttons associated with new actions.
 Use the `SCServiceCloud.actions` property to get access to `SCSActionManager` and the action button API.
 
 @see `SCServiceCloudDelegate`
 */
NS_SWIFT_NAME(ServiceCloud)
@interface SCServiceCloud : NSObject

/**
 Returns the shared service cloud manager for this process.
 
 @return Initialized shared instace.
 */
+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/**
 Directory URL where shared files will be stored on the filesystem.  If `nil`, the system will supply the appropriate path given the application context.  This value should be used if Snap-ins features will be accessible from multiple extensions within your application to ensure data is stored in a location accessible to all app extensions.
 
 @warning *NOTE* This value must be set prior to the initialization of any system resources or classes utilizing Snap-ins features.  The behavior is undefined if the value is changed after the fact.
 */
@property (class, nullable, nonatomic, copy) NSURL *sharedDataDirectory;

/**
 Identifies the primary window where view controllers should be placed when
 presented.
 
 This value is automatically determined under most circumstances, but in the 
 event that a custom value needs to be set, the `primaryWindow` property can 
 be set to a specific window that should be used.
 */
@property (nullable, nonatomic, strong) UIWindow *primaryWindow;

/**
 The delegate for the service interface manager.
 
 @see `SCServiceCloudDelegate`
 */
@property (nonatomic, weak, nullable) NSObject<SCServiceCloudDelegate> *delegate;

/**
 The appearance style to use in presented views and view controllers.
 
 The default value for this is `SCInterfaceStyleDefault`.  If this value is set 
 after the interface has already been presented, it results in the service 
 interface being dismissed.
 
 @warning We recommend that you only assign this property once in the
 lifetime of an application.  Changing interface styles at runtime may have
 unpredictable results, and the behavior is undefined.
 */
@property (nonatomic, copy) NSString *interfaceStyle;

/**
 Sets the appearance configuration for the service interface. If not specified,
 this value falls back to default values.
 
 @see `SCAppearanceConfiguration`
 */
@property (nonatomic, strong) SCAppearanceConfiguration *appearanceConfiguration;

/**
 Configuration object used to define the self-service parameters used to 
 enable with Cases and/or Knowledge features.
 
 @see `SCSServiceConfiguration`
 */
@property (nonatomic, strong) SCSServiceConfiguration *serviceConfiguration;

@end

@class SFUserAccount;
@interface SCServiceCloud (Authentication)

/**
 Specifies the authentication settings for the designated service.
 
 The service can be one of the `SCServiceType` enum values:
 
 - `SCServiceTypeCases`: for the Case Management service
 - `SCServiceTypeKnowledge`: for the Knowledge service
 
 @param settings Authentication settings for this service.
 @param serviceType The designated service.
 @param completion The completion block that is called after the SDK attempts to authenticate.
 
 @see `SCSAuthenticationSettings`
 */
- (void)setAuthenticationSettings:(nullable SCSAuthenticationSettings*)settings forServiceType:(SCServiceType)serviceType completion:(nullable void(^)(BOOL success, NSError * _Nullable error))completion;

/**
 Returns the authentication settings for the designated service type.
 
 The service can be one of the `SCServiceType` enum values:
 
 - `SCServiceTypeCases`: for the Case Management service
 - `SCServiceTypeKnowledge`: for the Knowledge service
 
 @param serviceType The designated service.
 
 @see `SCSAuthenticationSettings`
 */
- (nullable SCSAuthenticationSettings*)authenticationSettingsForServiceType:(SCServiceType)serviceType;

@end

@class SCSNotification;
@interface SCServiceCloud (Notifications)

/**
 Returns a concrete subclass of `SCSNotification` from a remote notification
 dictionary.
 
 Returns `nil` if the notification cannot be handled by the SDK.
 Use `-showInterfaceForNotification:` to show the view associated with this 
 notification.

 @param userInfo The remote notification dictionary.
 @see `-showInterfaceForNotification:`
 */
- (nullable SCSNotification*)notificationFromRemoteNotificationDictionary:(NSDictionary*)userInfo;

/**
 Shows the appropriate view related to the notification that is passed to this 
 method.
 
 Use `-notificationFromRemoteNotificationDictionary:` to convert an 
 `NSDictionary` into an `SCSNotification` object.
 
 @param notification The notification that determines what interface to show.
 @see `-notificationFromRemoteNotificationDictionary:`
 */
- (BOOL)showInterfaceForNotification:(SCSNotification*)notification;

@end

@class SCSActionManager;
@interface SCServiceCloud (ActionManager)

/**
 Access point for interacting with the floating action bar.

 @see `SCSActionManager`
 */
@property (nonatomic, strong, readonly) SCSActionManager *actions;

@end

NS_ASSUME_NONNULL_END
