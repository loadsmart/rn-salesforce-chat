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
#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class SCServiceCloud;
@class SFUserAccount;
@class SCSAuthenticationSettings;

@protocol SCSActionItemContainer, SCSActionItem;

/**
 Delegate protocol to interact with the Service SDK, and to make decisions on behalf of the SDK.
 
 @see `SCServiceCloud`
 */
@protocol SCServiceCloudDelegate <NSObject>

@optional

/**
 Tells the delegate when the interface is about to be displayed.

 If the controller is `nil`, this means no more controllers remain visible.
 
 @param serviceCloud  `SCServiceCloud` interface instance.
 @param controller View controller being displayed.
 @param animated   `YES` if the presentation is animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud willDisplayViewController:(nullable UIViewController*)controller animated:(BOOL)animated;

/**
 Calls the delegate after the interface was displayed.

 If the controller is `nil`, this means no more controllers remain visible.
 
 @param serviceCloud  `SCServiceCloud` interface instance.
 @param controller View controller being displayed.
 @param animated   `YES` if the presentation was animated.
 */
- (void)serviceCloud:(SCServiceCloud *)serviceCloud didDisplayViewController:(nullable UIViewController*)controller animated:(BOOL)animated;

/**
 Asks the delegate to provide a `UIViewControllerTransitioningDelegate` used when a view controller is about to be presented.
 
 By default, the SDK uses custom controllers for presentation and for transition animations. If you wish to customize the default behavior, implement this method and return an object conforming to `UIViewControllerTransitioningDelegate`.
 
 @param serviceCloud `SCServiceCloud` interface instance.
 @param controller   View controller about to be presented.

 @return Transitioning delegate that should control the controller presentation, or `nil` to accept the system defaults.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)serviceCloud:(SCServiceCloud *)serviceCloud transitioningDelegateForViewController:(UIViewController*)controller __deprecated_msg("Please use serviceCloud:transitioningDelegateForViewController:presentedFromController: instead");

/**
 Asks the delegate to provide a `UIViewControllerTransitioningDelegate` used when a view controller is about to be presented.

 By default, the SDK uses custom controllers for presentation and for transition animations. If you wish to customize the default behavior, implement this method and return an object conforming to `UIViewControllerTransitioningDelegate`.

 @param serviceCloud `SCServiceCloud` interface instance.
 @param presentedController View controller about to be presented.
 @param presentingController View controller the target controller is being presented from.  If this value is `nil`, it is assumed to be the first controller being presented at the time.

 @return Transitioning delegate that should control the controller presentation, or `nil` to accept the system defaults.
 */
- (nullable NSObject<UIViewControllerTransitioningDelegate>*)serviceCloud:(SCServiceCloud *)serviceCloud transitioningDelegateForPresentedController:(UIViewController*)presentedController presentingController:(nullable UIViewController*)presentingController;

/**
 Asks the delegate whether the specified action button should be present.

 The value of the action name can be one of these constants (defined in Service SDK):

 - `SCSActionCasePublisher`: for the case publisher action
 - `SCSActionCaseList`: for the case list action
 - `SCSActionArticleSearch`: for the knowledge article search action

 @param serviceCloud `SCServiceCloud` interface instance.
 @param name Name representing the action in question.
 @return `YES` if the action button should be visible; `NO` if the action button should be omitted.
 */
- (BOOL)serviceCloud:(SCServiceCloud *)serviceCloud shouldShowActionWithName:(NSString*)name __deprecated_msg("Please use the -[SCSActionManagerDelegate actionManager:shouldShowActionWithName:] method instead");

/**
 Deprecated. See `-serviceCloud:shouldAuthenticateServiceType:completion:`.
 */
- (BOOL)serviceCloud:(SCServiceCloud*)serviceCloud shouldAuthenticateService:(SCServiceType)service completion:(void(^)(SFUserAccount * _Nullable account))completion SCS_API_DEPRECATED_WITH_REPLACEMENT("setAuthenticationSettings:forServiceType:");

/**
 Deprecated. See `-serviceCloud:authenticationFailed:forServiceType:`.
 */
- (void)serviceCloud:(SCServiceCloud*)serviceCloud serviceAuthenticationFailedWithError:(NSError*)error SCS_API_DEPRECATED_WITH_REPLACEMENT("serviceCloud:authenticationFailed:forServiceType:");

/**
 Asks the delegate whether authentication should be performed for the specified service.
 
 The service can be one of the `SCServiceType` enum values:
 
 - `SCServiceTypeCases`: for the Case Management service
 - `SCServiceTypeKnowledge`: for the Knowledge service
 
 If the delegate returns `YES` to this method, the receiver must pass along the
 new authentication settings to the supplied completion block. These authentication
 settings are subsequently passed along to the
 `-[SCServiceCloud setAuthenticationSettings:forServiceType:completion:]` method.
 
 @param serviceCloud  `SCServiceCloud` interface instance.
 @param service The associated service.
 @param completion The completion block you should call when you've retrieved authentication credentials. If `nil` is assigned to the completion block, it is assumed that guest access is desired.
 @return `YES` if the receiver plans to supply authentication information for this service, otherwise `NO` if the current account credentials are sufficient.
 
 @see `SCSAuthenticationSettings`
 */
- (BOOL)serviceCloud:(SCServiceCloud*)serviceCloud shouldAuthenticateServiceType:(SCServiceType)service completion:(void(^)(SCSAuthenticationSettings * _Nullable settings))completion;

/**
 Tells the delegate when there is an error in authenticating Case Management or Knowledge.
 
 @param serviceCloud  `SCServiceCloud` interface instance.
 @param error The error message associated with the failure.
 @param service Service being authenticated.
 
 @return Whether the receiver wants to attempt to re-authenticate. If you specify `YES`, the SDK subsequently
 calls `-serviceCloud:shouldAuthenticateServiceType:completion:`. If you specify `NO`, the SDK reverts to guest user status.
 */
- (BOOL)serviceCloud:(SCServiceCloud*)serviceCloud authenticationFailed:(NSError*)error forServiceType:(SCServiceType)service;

/**
 Tells the delegate when there is a log message that has been sent to the logging server.
 
 @param serviceCloud  `SCServiceCloud` interface instance.
 @param message An array containing all the logging information.
 @param type The type of message that is being logged.
 */
- (void)serviceCloud:(SCServiceCloud*)serviceCloud didLogMessage:(NSArray* _Nonnull)message type:(NSString* _Nonnull)type;

@end

NS_ASSUME_NONNULL_END
