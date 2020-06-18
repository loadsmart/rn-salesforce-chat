/*
 * Copyright 2017 salesforce.com, inc.
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

@class SCSPrechatEntityField;

/**
 A `SCSPrechatEntity` specifies a salesforce entity related to this chat session
 that will be found or created on session start.

 This object must be added to your chat configuration using
 `SCSChatConfiguration.prechatEntities`.
 */
@interface SCSPrechatEntity : NSObject<NSCopying>

/**
 Name of the salesforce object being created or found. eg. Case or Contact
 */
@property (nonatomic, nonnull, readonly) NSString *entityName;

/**
 Indicates whether the entity should be shown to the console agent on creation.
 */
@property (nonatomic) BOOL showOnCreate;

/**
 The sibling entityName to which this entity should be mapped. @see `SCSPrechatEntity.linkToEntityField`
 */
@property (nonatomic, copy, nullable) NSString *linkToEntityName;

/**
 The field in a sibling entity to which this entity should be mapped. @see `SCSPrechatEntity.linkToEntityName`
 */
@property (nonatomic, copy, nullable) NSString *linkToEntityField;

/**
 The name of the field to which this entity should be linked in the LiveAgentChatTranscript object.
 */
@property (nonatomic, copy, nullable) NSString *saveToTranscript;

/**
 Array of `SCSPrechatEntityField` objects to define the mappings.
 */
@property (nonatomic, nonnull, readonly) NSMutableArray<SCSPrechatEntityField*> *entityFieldsMaps;

/**
 Instantiates an `SCSPrechatEntity` object for use with
 `SCSChatConfiguration.prechatEntities`.

 @param entityName Name of the salesforce object being created or found. eg. Case or Contact
 @return The `SCSPrechatEntity` instance.
 */
- (instancetype _Nonnull)initWithEntityName:(NSString * _Nonnull)entityName NS_DESIGNATED_INITIALIZER;

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end
