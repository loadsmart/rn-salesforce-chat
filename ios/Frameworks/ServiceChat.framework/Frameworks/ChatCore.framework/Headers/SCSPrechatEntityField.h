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

/**
 A `SCSPrechatEntityField` specifies a field of a salesforce object and its relation
 to a specific pre-chat object defined on session creation.

 This object must be added to a pre-chat entity using
 `SCSPrechatEntity.entityFieldsMaps`.
 */
@interface SCSPrechatEntityField : NSObject

/**
 Name of the field inside the `SCSPrechatEntity` to which the prechat field data should be mapped.
 */
@property (nonatomic, nonnull, readonly) NSString *fieldName;

/**
 Label of the `SCSPrechatObject` being mapped to by this field.
 */
@property (nonatomic, nonnull, readonly) NSString *label;

/**
 Indicates whether an existing entity should attempt to be found with this same field value.
 */
@property (nonatomic) BOOL doFind;

/**
 Indicates whether a search for an existing entity should have to match this field exactly.
 */
@property (nonatomic) BOOL isExactMatch;

/**
 Indicates whether an entity should be created if one is not found or not searched for.
 */
@property (nonatomic) BOOL doCreate;

/**
 Instantiates an `SCSPrechatEntityField` object for use with
 `SCSPrechatEntity.entityFieldsMaps`.

 @param fieldName Name of the field inside the `SCSPrechatEntity` to which the prechat field data should be mapped.
 @param label Label of the `SCSPrechatObject` being mapped to by this field.
 @return The `SCSPrechatEntityField` instance.
 */
- (instancetype _Nonnull)initWithFieldName:(NSString * _Nonnull)fieldName label:(NSString * _Nonnull)label NS_DESIGNATED_INITIALIZER;

- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end
