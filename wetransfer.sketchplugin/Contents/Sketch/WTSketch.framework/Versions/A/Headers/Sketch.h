//
//  Sketch.h
//  WTSketch
//
//  Created by Tom Lokhorst on 2017-08-28.
//  Copyright © 2017 Q42. All rights reserved.
//

#ifndef Sketch_h
#define Sketch_h

#endif /* Sketch_h */

@import Cocoa;

@interface BCOutlineViewDataController
@property(retain, nonatomic) NSArray *cachedNodesChildren;
- (BOOL)isNodeSelected:(id)node;
@end

@interface BCPageListViewController: NSObject
@property(retain, nonatomic) BCOutlineViewDataController *dataController;
@end

@interface BCSideBarViewController: NSObject
@property(retain, nonatomic) BCPageListViewController *pageListViewController;
@end

#pragma mark -
#pragma mark MSLayer


@interface MSLayer: NSObject
@property(copy, nonatomic) NSString *objectID;
@property(copy, nonatomic) NSString *name;
@property(readonly, nonatomic) NSString *displayName;
@property(readonly, nonatomic) BOOL isSelected;

- (void)removeFromParent;
- (id)allSymbolInstancesInChildren;
@end

#pragma mark -
#pragma mark MSLayerArray

@interface MSLayerArray: NSObject
@property(copy, nonatomic) NSArray *layers;
@end

#pragma mark -
#pragma mark MSLayerGroup

@interface MSLayerGroup: MSLayer
@property(readonly, nonatomic) NSArray<MSLayer *> *layers;
@end

#pragma mark -
#pragma mark MSPage

@interface MSPage: MSLayerGroup
@property(readonly, nonatomic) NSArray *symbols;
@end

#pragma mark -
#pragma mark MSDocument

@interface MSDocument: NSDocument

@property(copy, nonatomic) MSLayerArray *selectedLayers;
@property(retain, nonatomic) NSMutableDictionary *mutableUIMetadata;
@property(retain, nonatomic) BCSideBarViewController *sidebarController;
@property(retain, nonatomic) NSWindow *documentWindow;
- (void)showMessage:(NSString *)message;
- (NSArray<MSPage *> *)pages;
- (void)removePage:(MSPage *)page;
	
@end

#pragma mark -
#pragma mark MSSymbolInstance

@interface MSSymbolInstance: MSLayer
- (MSLayer *)symbolMaster;
@end
