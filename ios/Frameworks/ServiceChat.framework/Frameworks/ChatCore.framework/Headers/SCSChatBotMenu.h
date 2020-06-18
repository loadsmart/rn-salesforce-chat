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

@import ServiceCore.ServiceCommon.SCCDefines;

@protocol SCSChatBotMenuDelegate;

/**
 The type of chatbot menu. The following types are available:
 
   - `SCSChatBotWindowMenu`: A standard chatbot window menu.
   - `SCSChatBotQuickReplyMenu`: A quick reply button menu.
   - `SCSChatBotFooterMenu`: A persistent chatbot footer menu.
 
 @see `SCSChatBotMenu`
 */
typedef NSString *const SCSChatBotMenuType SCS_STRING_ENUM;

/**
 A standard chatbot window menu.
 */
FOUNDATION_EXPORT SCSChatBotMenuType SCSChatBotWindowMenu;

/**
 A quick reply button menu.
 */
FOUNDATION_EXPORT SCSChatBotMenuType SCSChatBotQuickReplyMenu;

/**
 A persistent chatbot footer menu.
 */
FOUNDATION_EXPORT SCSChatBotMenuType SCSChatBotFooterMenu;

/**
 Class that manages the chatbot menu. Use this class to get information
 related to a chatbot menu (`SCSChatBotMenu.title`, `SCSChatBotMenu.options`, `SCSChatBotMenu.type`),
 to subscribe to the chatbot menu delegate (`-addDelegate:`), and to
 send chatbot selections (`-makeSelectionAtIndex:`) back to the org.
 
 @see `SCSChatBotMenuDelegate`
 @see `SCSChatBotMenuType`
 */
@interface SCSChatBotMenu : NSObject

/**
 Array of chatbot menu options.
 */
@property (nonatomic, copy, readonly) NSArray<NSString *> *options;

/**
 Chatbot menu title.
 */
@property (nonatomic, strong, readonly) NSString *title;

/**
 Chatbot menu type.
 
 @see `SCSChatBotMenuType`
 */
@property (nonatomic, strong, readonly) SCSChatBotMenuType type;

/**
 Determines if the menu is still active. This property returns `false` after the menu
 receives a message that it is expired.
 */
@property (nonatomic, assign, readonly, getter=isActive) BOOL active;

/**
 Makes a selection at a specific index.
 
 @param index The index corresponding to the desired menu item.
 @return Indicates whether the selection was sent. Returns `false` if the menu is expired.
 */
- (BOOL)makeSelectionAtIndex:(NSUInteger)index;

/**
 Adds an instance of an `id` implementing the `SCSChatBotMenuDelegate` protocol
 to the list of delegates to notify.

 @param delegate `id` instance to add.
 */
- (void)addDelegate:(id<SCSChatBotMenuDelegate>)delegate NS_SWIFT_NAME( add(delegate:) );

/**
 Adds an instance of an `id` implementing the `SCSChatBotMenuDelegate` protocol
 to the list of delegates to notify.

 @param delegate `id` instance to add.
 @param queue `dispatch_queue_t` you wish your events to be called back on.
 */
- (void)addDelegate:(id<SCSChatBotMenuDelegate>)delegate queue:(dispatch_queue_t)queue NS_SWIFT_NAME( add(delegate:queue:) );

/**
 Removes the specified delegate from receiving events in the future.

 @param delegate The `SCSChatBotMenuDelegate` to be removed.

 @note Once the menu receives a message that it is expired. All delegates are removed
 automatically.
 */
- (void)removeDelegate:(id<SCSChatBotMenuDelegate>)delegate NS_SWIFT_NAME( remove(delegate:) );
@end
