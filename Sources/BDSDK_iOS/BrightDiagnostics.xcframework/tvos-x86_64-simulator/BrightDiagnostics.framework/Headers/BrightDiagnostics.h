//
//  BrightDiagnostics.h
//  Public API
//
// **********************************************************************************
// *                                                                                *
// *    Copyright (c) 2019 AT&T Intellectual Property. ALL RIGHTS RESERVED          *
// *                                                                                *
// *    This code is licensed under a personal license granted to you by AT&T.      *
// *                                                                                *
// *    All use must comply with the terms of such license. No unauthorized use,    *
// *    copying, modifying or transfer is permitted without the express permission  *
// *    of AT&T. If you do not have a copy of the license, you may obtain a copy    *
// *    of such license from AT&T.                                                  *
// *                                                                                *
// **********************************************************************************
//

#import <Foundation/Foundation.h>

/// :nodoc: Project version number for BrightDiagnostics.
FOUNDATION_EXPORT double BrightDiagnosticsVersionNumber;

/// :nodoc: Project version string for BrightDiagnostics.
FOUNDATION_EXPORT const unsigned char BrightDiagnosticsVersionString[];

// In this header, import all the public headers of the framework using statements like #import <BrightDiagnostics/PublicHeader.h>
#import <BrightDiagnostics/BRTStream.h>
#import <BrightDiagnostics/BRTConfiguration.h>

typedef NSString * const BRTConfigurationValidation NS_TYPED_ENUM;
/// A key for the set of configuration options that were valid
FOUNDATION_EXPORT BRTConfigurationValidation _Nonnull BRTConfigurationValidationValidKey;
/// A key for the set of configuration options that were invalid
FOUNDATION_EXPORT BRTConfigurationValidation _Nonnull BRTConfigurationValidationInvalidKey;

/// Result keys for applying configuration options
typedef NSString * const BRTConfigurationResult NS_TYPED_ENUM;
/// A key for the set of configuration items that were successfully applied
FOUNDATION_EXPORT BRTConfigurationResult _Nonnull BRTConfigurationResultAppliedKey;
/// A key for the set of configuration items that were not successfully applied
FOUNDATION_EXPORT BRTConfigurationResult _Nonnull BRTConfigurationResultFailedKey;

/// Keys for setting configuration options
typedef NSString * const BRTConfigurationOptions NS_TYPED_ENUM;
/**
 Set realtime uploads enabled/disabled
 
 The value of this key should be a `BOOL` indicating whether real time uploads are enabled/disabled.
 
 @see `BrightDiagnostics.realTimeUploadsEnabled`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsRealTimeUploadsKey = @"com.att.mobile.bdsdk.realtimeuploads";
/**
 Set desired location accuracy
 
 The value of this key should be an NSNumber indicating the desired location accuracy, corresponding to `CLLocationAccuracy` values.
 
 @see `BrightDiagnostics.desiredLocationAccuracy`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsDesiredLocationAccuracyKey = @"com.att.mobile.bdsdk.desiredlocationaccuracy";
/**
 Set monitoring significant location change
 
 The value of this key should be a `BOOL` indicating whether to enable monitoring significant location change as a collection trigger.
 
 @see `BrightDiagnostics.monitoringSignificantLocationChange`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsSignificantLocationChangeKey = @"com.att.mobile.bdsdk.monitorsignificantlocationchange";
/**
 Set monitoring visits (enables BrightDiagnostics.startMonitoringVisits).
 
 The value of this key should be a `BOOL` indicating whether to enable monitoring visits.
 
 @note Not available on tvOS.  The value may be set in the config file, but nothing will happen on tvOS devices.  This flag is always off on tvOS.
 
 @see `BrightDiagnostics.startMinitoringVisits`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsMonitorVisitsKey = @"com.att.mobile.bdsdk.monitorvisits";
/**
 Set country restriction ISO code.
 
 The value of this key should be a String indicating the ISO country code. Data will
 **only** be collected when the device is within this country.
 
 @see `BrightDiagnostics.countryCollectionRestriction`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsCountryCollectionRestrictionKey = @"com.att.mobile.bdsdk.countrycollectionrestriction";
/**
 Set crash reporter enabled/disabled
 
 The value of this key should be a `BOOL` indicating whether crashreporter is enabled/disabled.
 
 @see `BrightDiagnostics.enableCrashReporter`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsCrashReporterKey = @"com.att.mobile.bdsdk.crashreporter";


/**
 Specify types of data to be collected. If not provided, a default set of data is
 collected.
 
 The value of this key should be an array containing `BRTCollectedData` constants.
 
 @see `BrightDiagnostics.collectedData`
 */
static BRTConfigurationOptions _Nonnull BRTConfigurationOptionsCollectedDataKey = @"com.att.mobile.bdsdk.collecteddata";

/// Controls what data is collected
typedef NSString * BRTCollectedData NS_TYPED_ENUM;
/**
 Indicates device information will be collected
 
 @note *This setting is read-only, it is always on and may not be disabled*
 */
static BRTCollectedData const _Nonnull BRTCollectedDataDeviceInfo = @"com.att.mobile.bdsdk.deviceinfo";
/**
 Indicates application information will be collected
 
 @note *This setting is read-only, it is always on and may not be disabled*
 */
static BRTCollectedData const _Nonnull BRTCollectedDataApplicationInfo = @"com.att.mobile.bdsdk.applicationinfo";
/**
 Indicates location information will be collected if allowed by the user
 
 @note the user may disable location services in the privacy settings, or may grant either of *While in Use* or *Always* which may restrict the collection of location information, significant location change information and visit information
 */
static BRTCollectedData const _Nonnull BRTCollectedDataLocationInfo = @"com.att.mobile.bdsdk.locationinfo";
/**
 Indicates session information will be collected if available
 
 @note if the calling program does not use the default session information or provide the information with streaming information no session information will be collected by default
 */
static BRTCollectedData const _Nonnull BRTCollectedDataSessionInfo = @"com.att.mobile.bdsdk.sessioninfo";
/**
 Indicates stream information will be collected if available
 
 @note streaming information requires the calling program to submit information using the optional streaming API.  If no streaming API calls are made, no streaming information will be collected by default
 */
static BRTCollectedData const _Nonnull BRTCollectedDataStreamInfo = @"com.att.mobile.bdsdk.streaminfo";
/**
 Indicates advertising information will be collected if allowed by the user
 
 @note the user may disable advertising by enabling the *Limit Ad Tracking* privacy setting on the device
 */
static BRTCollectedData const _Nonnull BRTCollectedDataAdvertisingInfo = @"com.att.mobile.bdsdk.advertisinginfo";
/**
 Indicates cellular connection information will be collected
 
 @note *Not available on tvOS*
 */
static BRTCollectedData const _Nonnull BRTCollectedDataCellularInfo = @"com.att.mobile.bdsdk.cellularinfo";
/**
 Indicates WiFi connection information will be collected
 
 @note *Not available on tvOS*
 */
static BRTCollectedData const _Nonnull BRTCollectedDataWiFiInfo = @"com.att.mobile.bdsdk.wifiinfo";


/**
 The `BrightDiagnostics` API can be used via a single user entry point which
 will invoke a collection of diagnostic metrics and attempt to upload a
 package of information to the collection servers. This call should be placed
 at reasonable places within the calling application. Good places would be
 shortly after application launch, at points where the user is performing a
 function which identifies current location, at application close, and between
 sessions of whatever the calling program does, such as streaming events,
 downloading data, etc. The current SDK does not interact with the application
 user in any way. There are no pop-up screens or alert messages.
 
 Additional capabilities may be used by the calling application and may be
 enabled or disabled by individual API settings calls, via a configuration file,
 or by creating a configuration and calling the *configure* method for the
 configuration object.
 
 Each application scenario or engagement is controlled by an internal profile
 which determines how and when the data is packaged and uploaded to the collection
 servers.
 The optional configuration capabilities modify what data is allowed to be
 collected so the application can omit specific information which otherwise
 would be collected if allowed by the user privacy settings.
 */
@interface BrightDiagnostics : NSObject

/// The full name of the SDK
@property (nonatomic, readonly, class, nonnull) NSString *sdkName;

/// The current sdk version
@property (nonatomic, readonly, class, nonnull) NSString *sdkVersion;

/// The custom device ID
@property (nonatomic, class, nonnull) NSString *deviceID;

#pragma mark - Configuration

/**
 Enable / Disable data collection & uploads by the SDK.
 
 @note Any uploads already in progress will still complete
 when set to `false`.
 */
@property (nonatomic, class) BOOL enabled;

/**
 Set real-time data uploads on or off - defaults to off.
 
 This requests that uploads are performed immediately after collection,
 assuming we have a valid internet connection. If there is no current
 connection, the uploads are tried again at the next collection or when
 the application is paused, or about to terminate.
 
 When this is set to `NO`/`false`, data uploads are not performed in
 real-time immediately after data collection.  The data is buffered and
 is uploaded when the application starts, when the applicaion is paused
 or otherwise put in the background, and when the app is ready to be
 terminated.
 
 */
@property (nonatomic, class) BOOL realTimeUploadsEnabled;

/**
 Set to allow the app to be restarted when receiving a visit event when
 monitoring visits is enabled - defaults to off.
 
 When the app receives a notice it is about to terminate, BrightDiagnostics,
 by default, will stop monitoring visits and significate location changes to
 prevent the app from being restarted when location services delivers an
 update after the app terminates.  Setting this flag tells BrightDiagnostics
 to not disable monitoring (if it is enabled). This optional setting should
 ONLY be changed if the app has put the proper mechanism in place to handle
 a restart caused by receiving a location or visit update.
 
 Most apps do not have this capability by default, and should not change this
 setting.  Please review the Apple documentation on CLVisit startMonitoringVisits
 and CLLocationManager programming before changing this setting.
 */
@property (nonatomic, class) BOOL allowVisitsToRestartAppEnabled;

typedef double CLLocationAccuracy;  // typedef from CLLocation.h
/**
 Sets the desired location accuracy to use for all subsequent location requests.
 The default value is `kCLLocationAccuracyBest`; using only as accurate value as
 you need will provide more efficient power usage.
 
 @note This value does not affect Significant Location Change based collection.
 */
@property (nonatomic, class) CLLocationAccuracy desiredLocationAccuracy;

/// The ISO country code currently checking for restrictions, or `nil` if no restrictions are enabled.
@property (nonatomic, readonly, class, nullable) NSString *countryCollectionRestriction;

/**
 Restrict all collection to **within** the specified country only.
 
 When enabled, collection will only occur if the device's current location is
 within the specified ISO country code. If the current location is unknown,
 no collection will occur. An empty string code is treated the same as a `nil` value.
 
 @note If the ISO country code you pass in is not valid, it will be assumed that the location
 is outside the country and no collection will occur. For valid ISO country codes, see
 [ISO 3166 Country Codes](https://www.iso.org/iso-3166-country-codes.html).
 
 @see `CountryCollectionRestrictionKey`
 
 @param countryCode The two-letter ISO country code. Any invalid characters (non-letter characters), or
 strings of less than two letters are considered invalid and the restriction will not be set (returning `NO`/`false`)
 
 @return `YES`/`true` if a code was set or `NO`/`false` if not
 */
+ (BOOL)restrictCollectionToCountryCode:(NSString *_Nullable)countryCode NS_SWIFT_NAME(restrictCollection(countryCode:));

/// Completion block for configureWithOptions
typedef void (^ConfigureWithOptionsCompletion)(BOOL, NSDictionary<BRTConfigurationResult, NSArray<NSString *> *> *_Nullable);

/**
 Configure the SDK using a dictionary.
 The options successfully applied are placed in an array and set to the `BRTConfigurationResultAppliedKey` key in the dictionary from the completion block.
 The options that failed to be applied are placed in an array and set to the `BRTConfigurationResultFailedKey` key in the dictionary from the completion block.
 
 @param options  A dictionary of options. Passing in an empty dictionary or nil value will reset the configuration back to default values.
 @param completion  A completion block that gets called with a boolean, representing true on success or false if the configuration dictionary could not be applied,
 and also a dictionary with 2 arrays for the applied and for the failed options.
 @note the completion block can be called on a different queue
 */
+ (void)configureWithOptions:(NSDictionary<BRTConfigurationOptions, id> *_Nullable)options
                  completion:(ConfigureWithOptionsCompletion _Nullable)completion;

/**
 Validate that the input dictionary had valid keys and value types, that can be consumed by the configureWithOptions: API.
 The options successfully validated are placed in an array and set to the `BRTConfigurationValidationValidKey`  key in the returned dictionary.
 The options that failed the validation are placed in an array and set to the `BRTConfigurationValidationInvalidKey` key in the returned dictionary.
 
 @param options A dictionary of options.
 @return A dictionary with 2 arrays for the valid and for the invalid options.
 */
+ (NSDictionary<BRTConfigurationValidation, NSArray<NSString *> *> *_Nullable)validateConfigurationOptions:(NSDictionary<BRTConfigurationOptions, id> *_Nullable)options;

/// Completion block for configureWithConfiguration
typedef void (^ConfigureWithConfigurationCompletion)(BOOL);

/**
 Configure the SDK using a configuration object
 
 @param configuration  A BRTConfiguration object, use the builder pattern to build and configure one
 @param completion  A completion block that gets called with a boolean, representing true on success or false if the configuration could not be applied
 @note the completion block can be called on a different queue
 */
+ (void)configureWithConfiguration:(BRTConfiguration *_Nullable)configuration
                        completion:(ConfigureWithConfigurationCompletion _Nullable)completion;

/**
 Enable / Disable the crash report collection & uploads by the SDK.
 
 @note Once CrashReporter is enabled it will collect the crash data to process and uploads on BrighgtDiagnostics Initialization.
 Any uploads already in progress will still complete when set to `false`.
 */
@property (nonatomic, class) BOOL enabledCrashReporter;


#pragma mark - Collecting Data

/**
 Manually collect a set of metrics, and upload them to the collection server.
 */
+ (void)collect;

/**
 The specific items to be collected when calling `collect`. If not changed, a default set of data will be collected.
 
 @see `collectedInformation` for valid values.
 */
@property (nonatomic, class, nonnull) NSSet<BRTCollectedData> *collectedInformation;


#pragma mark - Time Based Triggers

/// Indicates if timer based collection is enabled
@property (nonatomic, readonly, class) BOOL timedCollectionEnabled;

/**
 Start timer based collection on the given time interval.
 
 Runs indefinitely until `+stopTimedCollection` is called. If
 a timed trigger was already started, it will be canceled and replaced
 with the new interval.
 
 @note Passing in a negative or zero time interval will be ignored.
 
 @param timeInterval The interval to collect.
 @return True on success, false if the timer could not be started
 */
+ (BOOL)startTimedCollectionWithTimeInterval:(NSTimeInterval)timeInterval NS_SWIFT_NAME(startTimedCollection(timeInterval:));

/** Stop timer based collection */
+ (void)stopTimedCollection;

#pragma mark - Location Based Triggers

#if !TARGET_OS_TV

/// Indicates if timer based collection is enabled
@property (nonatomic, readonly, class) BOOL monitoringSignificantLocationChange;

/**
 Start collecting based on signifcant location change.
 
 *Not available on tvOS.*
 
 @note Prior to calling this method, you must have already obtained Location Always Authorization.
 To enable monitoring in the background, you must enable the *Location updates Background Mode*
 for your app and set the `CLLocationManager` property `allowsBackgroundLocationUpdates` to `true`.
 See BDSDK integration guide for details.
 
 @return True on success, false if significant location change is not
 available on the device or Location Always authorization is not granted.
 */
+ (BOOL)startSignificantLocationChangeCollection __TVOS_PROHIBITED;

/** Stop monitoring using significant location change.
 
 *Not available on tvOS.*
 */
+ (void)stopSignificantLocationChangeCollection __TVOS_PROHIBITED;

/**
 Start Monitoring Visits
 
 *Not available on tvOS.*
 
 @note Prior to calling this method, you must have already obtained Location Always Authorization.
 To enable monitoring in the background, you must enable the *Location updates Background Mode*
 for your app and set the `CLLocationManager` property `allowsBackgroundLocationUpdates` to `true`.
 See BDSDK integration guide for details.
 
 @return True on success, false if monitoring visits is not
 available on the device or Location Always authorization is not granted.
 */
+ (BOOL)startMonitoringVisits __TVOS_PROHIBITED;

/**
 Stop Monitoring Visits
 
 *Not available on tvOS.*
 */
+ (void)stopMonitoringVisits __TVOS_PROHIBITED;

#endif


@end