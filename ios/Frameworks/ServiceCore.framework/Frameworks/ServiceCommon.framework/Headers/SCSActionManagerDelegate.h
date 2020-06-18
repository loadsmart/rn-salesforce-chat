//
//  SCSActionManagerDelegate.h
//  ServiceCommon
//
//  Created by Amit Gosar on 4/10/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class SCSActionManager;
@protocol SCSActionItem, SCSActionItemContainer;

/**
 Delegate protocol used by the `SCSActionManager` to customize the appearance and functionality of the action manager.
 */
@protocol SCSActionManagerDelegate <NSObject>

@optional

/**
 Asks the delegate for a view controller to present action buttons to the user when it is about to be presented.
 
 This method should only be used when a developer wishes to customize the appearance of the action buttons, or when the action display controller should be disallowed.
 
 If no action buttons should be displayed to the user, this method can return `nil`.
 
 If this is a view controller, it will be presented in the UI for you.  Otherwise, your application is responsible for managing the display of these items yourself.
 
 @param actionManager `SCSActionManager` instance.
 @return Constructed UIViewController instance, conforming to the `SCSActionItemContainer` protocol, or `nil` if no action button controller should be shown.
 */
- (nullable __kindof UIViewController<SCSActionItemContainer> *)actionManagerContainerViewController:(SCSActionManager*)actionManager;

/**
 Asks the delegate to supply a custom view for the action of the given name.  If the return value is `nil`, the default system-provided view will be used, if any.
 
 The view is expected to trigger the action as needed using the `-[SCSActionManager performActionWithName:actionItem:]`.
 
 @param actionManager `SCSActionManager` instance.
 @param name Action name.
 @return `UIView` conforming to `SCSActionItem` to represent the given action, or `nil` to accept the system default.
 */
- (nullable __kindof UIView<SCSActionItem> *)actionManager:(SCSActionManager*)actionManager viewForActionItemWithName:(SCSAction)name;

/**
 Asks the delegate to indicate the relative sort positioning of the given action item.

 @param actionManager `SCSActionManager` instance.
 @param name Action name.
 @return Integer value indicating the sort position of the given action.
 */
- (NSInteger)actionManager:(SCSActionManager*)actionManager sortIndexForActionItemWithName:(SCSAction)name;

/**
 Asks the delegate for the set of named actions that should be shown when the given controller is presented.  If this method is not implemented a set of defaults is automatically determined.  This default set of actions is supplied to this method to allow the default behavior to be maintained when needed, or to extend or subtract from the default set.
 
 When no controllers are visible, the `controller` property may be `nil`.

 @param actionManager `SCSActionManager` instance.
 @param controller The controller that is being presented, or `nil` if the last controller has been dismised.
 @param defaultActions The default actions that would be displayed for this given controller.
 @return Set of string action item names to display.
 */
- (nullable NSSet<SCSAction>*)actionManager:(SCSActionManager *)actionManager actionsToShowForViewController:(nullable UIViewController*)controller withDefaultActions:(NSSet<SCSAction>*)defaultActions;

/**
 Asks the delegate whether or not the action container should be shown when the given controller becomes visible.  This provides the delegate with the opportunity to conditionally show or hide the action items when the visible state of the Service SDK changes.

 If the resulting container visibility is different from the current state, the appropriate change will be made, and the accompanying `-[SCSActionManagerDelegate actionManager:containerWillChangeVisibility:animated:]` and `-[SCSActionManagerDelegate actionManager:containerDidChangeVisibility:animated:]` methods will be invoked as needed.
 
 If the supplied controller's presentation, or dismissal, is animated, this will result in the action container's visibility change being animated as well.

 @param actionManager The action manager instance.
 @param controller The controller about to be presented, or `nil` if the last controller is being dismissed.
 @return `YES` if the container should be visible, otherwise `NO` if the action container should be hidden.
 */
- (BOOL)actionManager:(SCSActionManager *)actionManager shouldShowContainerForViewController:(nullable UIViewController*)controller;

/**
 Message sent to the delegate when the action container will change its visibility, either to be shown or hidden.

 @param actionManager The action manager instance.
 @param visible `YES` if the action container will become visible, otherwise `NO` if the action bar will become hidden.
 @param animated `YES` if the visibility change will be animated.
 */
- (void)actionManager:(SCSActionManager *)actionManager containerWillChangeVisibility:(BOOL)visible animated:(BOOL)animated;

/**
 Message sent to the delegate after the action container has changed its visibility, either to be shown or hidden.

 @param actionManager The action manager instance.
 @param visible `YES` if the action container became visible, otherwise `NO` if the action bar is hidden.
 @param animated `YES` if the visibility change was animated.
 */
- (void)actionManager:(SCSActionManager *)actionManager containerDidChangeVisibility:(BOOL)visible animated:(BOOL)animated;

/**
 @return `YES` if the action was handled, or `NO` if the default behavior should be performed for this action.
 */
- (BOOL)actionManager:(SCSActionManager *)actionManager performActionWithName:(SCSAction)actionName actionItem:(nullable UIView<SCSActionItem>*)actionItem;

/**
 Asks the delegate whether the specified action button should be present.
 
 @param actionManager `SCSActionManager` instance.
 @param name Name representing the action in question.
 @return `YES` if the action button should be visible; `NO` if the action button should be omitted.
 */
- (BOOL)actionManager:(SCSActionManager *)actionManager shouldShowActionWithName:(SCSAction)name;

@end

NS_ASSUME_NONNULL_END
