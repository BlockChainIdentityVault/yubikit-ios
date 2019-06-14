// Copyright 2018-2019 Yubico AB
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

#import "YKFKeyCommandConfiguration.h"
#import "EASession+Testing.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^YKFKeyConnectionControllerCommandResponseBlock)(NSData* _Nullable, NSError* _Nullable);
typedef void (^YKFKeyConnectionControllerCompletionBlock)(void);

@protocol YKFKeyConnectionControllerProtocol

- (void)execute:(NSData *)command completion:(YKFKeyConnectionControllerCommandResponseBlock)completion;
- (void)execute:(NSData *)command configuration:(YKFKeyCommandConfiguration *)configuration completion:(YKFKeyConnectionControllerCommandResponseBlock)completion;

- (void)dispatchOnSequentialQueue:(YKFKeyConnectionControllerCompletionBlock)block delay:(NSTimeInterval)delay;
- (void)dispatchOnSequentialQueue:(YKFKeyConnectionControllerCompletionBlock)block;

- (void)closeConnectionWithCompletion:(YKFKeyConnectionControllerCompletionBlock)completion;
- (void)cancelAllCommands;

@end

@interface YKFKeyConnectionController : NSObject<YKFKeyConnectionControllerProtocol>

- (nullable instancetype)initWithSession:(id<YKFEASessionProtocol>)session operationQueue:(NSOperationQueue *)operationQueue NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END