/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <CoreSimulator/SimDeviceNotifier-Protocol.h>

@class NSMutableDictionary;
@protocol OS_dispatch_queue;

@interface SimDeviceNotificationManager : NSObject <SimDeviceNotifier>
{
    NSObject<OS_dispatch_queue> *_handlersQueue;
    NSMutableDictionary *_handlers;
    unsigned long long _next_regID;
    NSObject<OS_dispatch_queue> *_sendQueue;
}

@property (retain, nonatomic) NSObject<OS_dispatch_queue> *sendQueue;
@property (nonatomic, assign) unsigned long long next_regID;
@property (retain, nonatomic) NSMutableDictionary *handlers;
@property (retain, nonatomic) NSObject<OS_dispatch_queue> *handlersQueue;

- (void)sendNotification:(id)arg1;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (id)init;

@end

