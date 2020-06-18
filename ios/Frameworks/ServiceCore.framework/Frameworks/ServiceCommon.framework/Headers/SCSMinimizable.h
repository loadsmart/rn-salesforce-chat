//
//  SCSMinimizable.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2017-03-31.
//  Copyright © 2017 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SCS_MINIMIZABLE_SUPPORTED

NS_ASSUME_NONNULL_BEGIN

@protocol SCSMinimizable;

/**
 Delegate protocol used to interact with, and be informed of changes to, minimizable controllers.
 */
@protocol SCSMinimizableDelegate <NSObject>

@optional

/**
 Overrides the destination point that the minimization will animate to.

 The point is a floating point value between 0.0 and 1.0 to indicate a relative position across the screen.  If any dimension in the point is larger than 1.0, it will be assumed to be an absolute position on the screen, and its value will be converted.  If you want to accept the previous position the attachment was minimized to, or you want to accept the system default, simply return the supplied `defaultPoint`.

 @param minimized The minimized controller.
 @param defaultPoint The default point that would be used.
 @return New point to serve as the initial destination point.
 */
- (CGPoint)minimizedController:(UIViewController<SCSMinimizable>*)minimized destinationPoint:(CGPoint)defaultPoint;

/**
 Informs the receiver when the minimized view is moved to a new point.

 @param minimized The minimized controller.
 @param point The new center point for the attachment.
 */
- (void)minimizedController:(UIViewController<SCSMinimizable>*)minimized movedToPoint:(CGPoint)point;

/**
 Notifies the receiver when the minimized view will be minimized.

 @param minimized The minimized controller.
 @param animated Whether or not the minimization will be animated.
 */
- (void)minimizedController:(UIViewController<SCSMinimizable>*)minimized controllerWillMinimize:(BOOL)animated;

/**
 Notifies the receiver when the window minimization is complete.

 @param minimized The minimized controller.
 @param animated Whether or not the minimization was animated.
 */
- (void)minimizedController:(UIViewController<SCSMinimizable>*)minimized controllerDidMinimize:(BOOL)animated;

/**
 Notifies the receiver when the window will be maximized.

 @param minimized The minimized controller.
 @param animated Whether or not the maximization will be animated.
 */
- (void)minimizedController:(UIViewController<SCSMinimizable>*)minimized controllerWillMaximize:(BOOL)animated;

/**
 Notifies the receiver when the window was maximized.

 @param minimized The minimized controller.
 @param animated Whether or not the maximization was animated.
 */
- (void)minimizedController:(UIViewController<SCSMinimizable>*)minimized controllerDidMaximize:(BOOL)animated;

@end

/**
 Protocol used by UI components that are capable of being minimized.
 */
@protocol SCSMinimizable <NSObject>

/**
 Indicates whether or not the receiver is capable of being minimized.
 */
@property (nonatomic, assign, getter=isMinimizable, readonly) BOOL minimizable;

/**
 Property to control whether or not the window is minimized.
 
 @see setMinimized:animated:completion:
 */
@property (nonatomic, assign, getter=isMinimized) BOOL minimized;

/**
 Optional delegate property used to interact with minimized views.
 */
@property (nullable, nonatomic, weak) NSObject<SCSMinimizableDelegate> *minimizationDelegate;

/**
 Animated setter for controlling the window minimification.
 @param minimized Boolean indicating if the view should be minimized or not.
 @param animated Indicates whether or not the minimization should occur with an animation.
 @param completion Optional completion block to be called when the operation has completed.
 */
- (void)setMinimized:(BOOL)minimized animated:(BOOL)animated completion:(nullable void(^)(void))completion;

@end

NS_ASSUME_NONNULL_END
