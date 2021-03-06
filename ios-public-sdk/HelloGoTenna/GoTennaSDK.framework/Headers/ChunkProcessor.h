//
//  ChunkProcessor.h
//  goTenna SDK
//
//  Created by Julietta Yaunches on 29/05/2014.
//  Copyright (c) 2014 goTenna. All rights reserved.
//

#import <Foundation/Foundation.h>

extern const unsigned char gtBluetoothCodeSTX[];
extern const unsigned char gtBluetoothCodeETX[];
extern const unsigned char gtBluetoothCodeDLE[];

@interface ChunkProcessor : NSObject

- (void)registerIncomingReadChunk:(NSData *)chunk;

@end
