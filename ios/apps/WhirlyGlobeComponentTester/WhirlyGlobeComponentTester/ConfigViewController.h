/*
 *  ConfigViewController.h
 *  WhirlyGlobeComponentTester
 *
 *  Created by Steve Gifford on 7/23/12.
 *  Copyright 2011-2013 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import <UIKit/UIKit.h>

// Base image layers
#define kMaplyTestCategoryBaseLayers @"Base Layers"

#define kMaplyTestBlank @"Blank"
#define kMaplyTestGeographyClass @"Geography Class - Local"
#define kMaplyTestBlueMarble @"NASA Blue Marble - Local"
#define kMaplyTestStamenWatercolor @"Stamen Watercolor - Remote"
#define kMaplyTestOSM @"OpenStreetMap (Mapquest) - Remote"
#define kMaplyTestCartoDBDarkMatter @"CartoDB Dark Matter - Remote"
#define kMaplyTestNightAndDay @"Night/Day Images - Remote"
#define kMaplyTestQuadTest @"Quad Test Layer"
#define kMaplyTestQuadTestAnimate @"Quad Test Layer - Animated"
#define kMaplyTestQuadVectorTest @"Quad Vector Test Layer"
#define kMaplyTestElevation @"Cesium Elevation Test Layer"

// Overlay image layers
#define kMaplyTestCategoryOverlayLayers @"Overlay layers"

#define kMaplyTestOWM @"OpenWeatherMap - Remote"
#define kMaplyTestForecastIO @"Forecast.IO Snapshot - Remote"
#define kMaplyMapzenVectors @"Mapzen Vectors - Remote"
#define kMaplyWindTest @"Wind Particles - Remote"
#define kMaplyOrdnanceSurveyTest @"British National Grid Test - Local"
#define kMaplyAerisTest @"Aeris Weather - Remote"

// Objects we can display
#define kMaplyTestCategoryObjects @"Maply Objects"

#define kMaplyTestLabel2D @"Labels - 2D"
#define kMaplyTestLabel3D @"Labels - 3D"
#define kMaplyTestMarker2D @"Markers - 2D"
#define kMaplyTestMarker3D @"Markers - 3D"
#define kMaplyTestSticker @"Stickers"
#define kMaplyTestShapeCylinder @"Shapes: Cylinders"
#define kMaplyTestShapeSphere @"Shapes: Spheres"
#define kMaplyTestShapeGreatCircle @"Shapes: Great Circles"
#define kMaplyTestShapeArrows @"Shapes: Arrows"
#define kMaplyTestModels @"Models"
#define kMaplyTestCountry @"Countries"
#define kMaplyTestLoftedPoly @"Lofted Polygons"
#define kMaplyTestQuadMarkers @"Quad Paging Markers"
#define kMaplyTestMegaMarkers @"Mega Markers"
#define kMaplyTestMarkerCluster @"Marker Clustering"
#define kMaplyTestLatLon @"Lon/Lat lines"
#define kMaplyTestRoads @"Wide Linear Test"
#define kMaplyTestArcGIS @"ArcGIS Vectors"
#define kMaplyTestStarsAndSun @"Stars and Sun"

// Animation
#define kMaplyTestCategoryAnimation @"Animation"

#define kMaplyTestAnimateSphere @"Animated Sphere"

// Gestures
#define kMaplyTestCategoryGestures @"Gestures"

#define kMaplyTestNorthUp @"Keep North Up"
#define kMaplyTestPan @"Pan Gesture"
#define kMaplyTestPinch @"Pinch Gesture"
#define kMaplyTestRotate @"Rotate Gesture"

// Low level
#define kMaplyTestCategoryInternal @"Internals"
#define kMaplyTestCulling @"Culling Optimization"
#define kMaplyTestPerf @"Performance Output"


// Section in the configuration panel
@interface ConfigSection : NSObject

// Section name (as dispalyed to user)
@property NSString *sectionName;

// Entries (name,boolean) within the section
@property NSMutableDictionary *rows;

// If set, user can only select one of the options
@property bool singleSelect;

// Construct a config section
+ (ConfigSection *)ConfigSectionWithName:(NSString *)sectionName rows:(NSDictionary *)rowDict singleSelect:(bool)select;

@end

typedef enum {ConfigOptionsGlobe,ConfigOptions3DTerrain,ConfigOptionsMap} ConfigOptions;

// Configuration view lets the user decide what to turn on and off
@interface ConfigViewController : UIViewController <UITableViewDataSource,UITableViewDelegate>

// Dictionary reflecting the current values from the table
@property (nonatomic,readonly) NSArray *values;

// What we'll display in terms of user options
@property (nonatomic,assign) ConfigOptions configOptions;

// Return the configuration value for a section/row
- (bool)valueForSection:(NSString *)section row:(NSString *)row;

@end
