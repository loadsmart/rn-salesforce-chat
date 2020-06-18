//
//  SCServiceLogger.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2018-02-05.
//  Copyright © 2018 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <os/log.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Logging level enumerated type. Use with `SCServiceLogger`.
 */
typedef NS_ENUM(uint8_t, SCSLoggerLevel) {
    SCSLoggerLevelDebug   = OS_LOG_TYPE_DEBUG,
    SCSLoggerLevelInfo    = OS_LOG_TYPE_INFO,
    SCSLoggerLevelDefault = OS_LOG_TYPE_DEFAULT,
    SCSLoggerLevelError   = OS_LOG_TYPE_ERROR,
    SCSLoggerLevelFault   = OS_LOG_TYPE_FAULT,
    SCSLoggerLevelOff     = 0xFF,
};

/**
 Facility used to customize the logging level, and optional file output, of the Snap-ins components.
 */
NS_SWIFT_NAME(ServiceLogger)
@interface SCServiceLogger : NSObject

/**
 Shared singleton instance used to configure logging.
 */
@property (nonatomic, strong, class, readonly) SCServiceLogger *sharedLogger NS_SWIFT_NAME(shared);

/**
 The current log level to filter messages at.
 
 @see `SCSLoggerLevel`
 */
@property (nonatomic, assign) SCSLoggerLevel level;

/**
 Optional file handle used to write log messages to disk.
 */
@property (nullable, nonatomic, strong) NSFileHandle *filehandle;

/**
 Sets the logger to the specified level filtering for the specified prefix.
 
 @note In most scenarios, you should use the `level` property instead.
 
 @param level The log level as a `SCSLoggerLevel` type.
 @param prefix The log message prefix.
 
 @see `level`
 */
- (void)setLogLevel:(SCSLoggerLevel)level forSubsystemsWithPrefix:(NSString*)prefix;

@end

NS_ASSUME_NONNULL_END
