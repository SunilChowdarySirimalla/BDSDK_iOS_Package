Pod::Spec.new do |spec|

  spec.name          = "BrightDiagnostics"
  spec.version       = "3.0.7"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.homepage     = "http://docs.wmcdp.io/docs/prism/ios/gettingstarted/"
  spec.authors       = { 'Sunil' => 'ss@gmail.com' }
  spec.summary       = "BrightDiagnostics XCFramework"
  spec.description   = "BrightDiagnostics XCFramework is a framework for both iOS and tvOS"
  spec.ios.deployment_target = "11.0"
  spec.source        = { :git => "https://github.com/SunilChowdarySirimalla/BDSDK_iOS_Package.git", :tag => spec.version }
  spec.source_files = 'Sources/BrightDiagnostics.xcframework/**/BrightDiagnostics.framework/Headers/*.h'
  spec.swift_version = "5.0"
    
end