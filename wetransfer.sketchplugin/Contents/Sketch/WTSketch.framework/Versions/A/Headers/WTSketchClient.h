//
//  WTSketchClient.h
//  WTSketch
//
//  Created by Sander de Vos on 29/08/2017.
//  Copyright © 2017 Q42. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MSDocument, MSContext;

@interface WTSketchClient : NSObject

+ (void)uploadSelection:(MSDocument *)document pluginRoot:(NSString *)pluginRoot;
+ (void)showOnboardingIfNeeded;

@end
