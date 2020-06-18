//
//  SCSActionItemContainer.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCCDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SCSActionItem;

/**
 Protocol defining a type of `UIViewController` that can be used to display `SCSActionItem` objects.
 
 @see `SCSActionManager`
 */
@protocol SCSActionItemContainer <NSObject>

/**
 Adds an action view for the given name.
 
 This will insert the view into the view hierarchy, and will include it sorted with the set of views if applicable.  A built-in animation is provided if the animated property is `YES`.
 
 @param view      The action view to add.
 @param name      The name of the action.
 @param sortIndex Preferred sort position relative to other views, or `NSNotFound` for no preference.
 @param animated  Indicates if the addition should be animated.
 */
- (void)addActionView:(UIView<SCSActionItem>*)view forName:(SCSAction)name atSortIndex:(NSInteger)sortIndex animated:(BOOL)animated;

/**
 Removes the action view with the given name.
 
 @param name     Name of the action to remove.
 @param animated Indicates if the removal should be animated.
 */
- (void)removeActionViewForName:(SCSAction)name animated:(BOOL)animated;

/**
 Returns the action view with the given name.
 
 If no action view is visible with that name, this method can return `nil`.
 
 @param name Name of the action.
 
 @return Action view with that name, or `nil` if no view matches that name.
 */
- (nullable UIView<SCSActionItem>*)actionViewForName:(SCSAction)name;

/**
 Returns the names for the currently-visible action views.
 
 @return Ordered list of visible action names.
 */
- (NSArray<SCSAction>*)visibleActionNames;

@optional

/**
 Indicates whether or not the item container should automatically adjust its visibility when the content on the screen scrolls.
 
 If not implemented, the default is assumed to be `NO`.
 
 @return `YES` if scrollable content should cause the action container to show or hide, otherwise `NO`.
 */
- (BOOL)shouldAdjustVisibilityWhenContentScrolls;

@end

NS_ASSUME_NONNULL_END
