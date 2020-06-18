//
//  SCSActionManager.h
//  ServiceCommon
//
//  Created by Amit Gosar on 4/10/17.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCDefines.h"
#import "SCSActionManagerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCSActionItem, SCSActionItemContainer, SCSActionManagerDelegate;

/**
 The SCSActionManager class controls the handling and display of the action buttons that are overlaid on the various Snap-ins SDK interface elements to allow the user to initiate various actions, such as:
 
 - Creating a new case.
 - Initiating a knowledge article search.
 - Starting a Live Agent chat session.
 - Initiating an SOS support session.
 
 These built-in actions are managed through the action manager class, and can be customized through the use of it and the associated protocols available.  Furthermore, the `SCSActionManagerDelegate` protocol can be used to interact with, and customize, the handling of these actions.
 
 Each action button that is displayed is represented by `UIView` instances that conform to the `SCSActionItem` protocol.  Each of these items are displayed within a `UIViewController` instance that conforms to the `SCSActionItemController` protocol.  Built-in defaults are provided that implement these behaviors, and can be used to extend or customize functionality.  Furthermore, the default action button is exposed as the `SCSActionButton` class, and can be used to introduce additional actions along side the built-in defaults, while still maintaining the same visual appearance.
 */
@interface SCSActionManager : NSObject

/**
 Delegate property for interacting with, and customizing, the action manager.
 
 @see `SCSActionManagerDelegate`
 */
@property (nonatomic, weak) NSObject<SCSActionManagerDelegate> *delegate;

/**
 Indicates that the set of available action items may have changed, and informs the `SCSActionManager` that it should reevaluate its set of available options.
 */
- (void)setNeedsUpdateActionItems;

/**
 Reference to the current action display controller.
 */
@property (nullable, nonatomic, strong, readonly) UIViewController<SCSActionItemContainer> *actionItemContainer;

/**
 Indicates whether or not the action item container is visible.
 
 Under normal circumstances the action container will automatically show and hide based on whether or not the current display supports it.  This behavior can be extended or customized within the `-[SCSActionManagerDelegate actionManager:shouldShowContainerForViewController:]` delegate method.  When all remaining ServiceSDK UI elements have been dismissed, the action container will automatically be cleaned up and removed from the view hierarchy. However, if the `containerVisible` property is set directly, this default behavior is opted out, allowing the container to remain visible after the ServiceSDK elements have been dismissed.

 @see `-[SCSActionManager setContainerVisible:animated:]`
 */
@property (nonatomic, assign, getter=isContainerVisible) BOOL containerVisible;

/**
 Animated setter for controlling the action item container visibility.

 @param visible `YES` if the action container should be visible, or `NO` to make the container hidden.
 @param animated Indicates whether or not the container visibility change should be animated.
 @see `containerVisible`
 */
- (void)setContainerVisible:(BOOL)visible animated:(BOOL)animated;

/**
 Indicates whether or not an action with the given name is currently visible.
 
 @param actionName Action name.
 
 @return `YES` if the action is visible.
 */
- (BOOL)isActionItemWithNameVisible:(SCSAction)actionName NS_SWIFT_NAME(isActionItemVisible(_:));

/**
 Shows or hides an action with the given name.
 
 If the `-[SCServiceCloudDelegate serviceCloud:shouldShowActionWithName:]` delegate method is implemented, the result of that method is respected regardless of which value is supplied to this method.
 
 @param visible  `YES` If the action should be visible, or `NO` if the action should be hidden.
 @param name     Action name.
 @param animated `YES` If the action's view should be animated.
 */
- (void)setActionItemWithName:(SCSAction)name visible:(BOOL)visible animated:(BOOL)animated NS_SWIFT_NAME(setActionItemVisible(name:visible:animated:));

/**
 Performs the action associated with the action name for the supplied action item.
 
 @param actionName Name of the action to perform.
 @param actionItem Action item for which the action needs to be performed.
 
 */
- (void)performActionWithName:(SCSAction)actionName actionItem:(nullable UIView<SCSActionItem>*)actionItem NS_SWIFT_NAME(performAction(_:actionItem:));

@end

NS_ASSUME_NONNULL_END
