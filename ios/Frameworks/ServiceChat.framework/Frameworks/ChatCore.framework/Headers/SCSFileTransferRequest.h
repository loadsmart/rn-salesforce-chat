/*
 * Copyright 2016-2018 salesforce.com, inc.
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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol SCSFileTransferDelegate;

/**
 Information about a file transfer request.
 */
@interface SCSFileTransferRequest : NSObject

/**
 Determines if the request is still active. This property returns `false`/`NO` after the file transfer
 has completed regardless of whether the transfer was successful.
 */
@property (nonatomic, assign, readonly, getter=isActive) BOOL active;

/**
 `UIImage` that has been attached to this request.
 */
@property (nonatomic, strong, readonly) UIImage *image;

/**
 Sends the specified image to the agent.
 
 @param image `UIImage` we are sending through this request.
 */
- (void)sendImage:(UIImage *)image;

/**
 Adds an instance of an `id` implementing the `SCSFileTransferDelegate` protocol
 to the list of delegates to notify.

 @param delegate `id` instance to add.
 */
- (void)addDelegate:(id<SCSFileTransferDelegate>)delegate NS_SWIFT_NAME( add(delegate:) );

/**
 Adds an instance of an `id` implementing the `SCSFileTransferDelegate` protocol
 to the list of delegates to notify.

 @param delegate `id` instance to add.
 @param queue `dispatch_queue_t` you wish your events to be called back on.
 */
- (void)addDelegate:(id<SCSFileTransferDelegate>)delegate queue:(dispatch_queue_t)queue NS_SWIFT_NAME( add(delegate:queue:) );

/**
 Removes the specified delegate from receiving events in the future.

 @param delegate The `SCSFileTransferDelegate` which will be removed.

 @note Once the file transfer receives a message that it is expired, completed or failed. All delegates will be removed
 automatically
 */
- (void)removeDelegate:(id<SCSFileTransferDelegate>)delegate NS_SWIFT_NAME( remove(delegate:) );

@end
