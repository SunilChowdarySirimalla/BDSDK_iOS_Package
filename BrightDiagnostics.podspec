Pod::Spec.new do |spec|

  spec.name         = "BrightDiagnostics"
  spec.version      = "3.0.8"
  spec.summary      = "BrightDiagnostics SDK for the Apple ecosystem"
  spec.description  = "BrightDiagnostics SDK for iOS contains the feature to collect data"
  spec.homepage     = "http://docs.wmcdp.io/docs/prism/ios/gettingstarted/"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "Sunil Chowdary Sirimalla" => "ss079m@att.com" }
  spec.documentation_url = "http://docs.wmcdp.io/docs/prism/ios/gettingstarted/"
  spec.ios.deployment_target = "12.0"
  spec.tvos.deployment_target = "12.0"
  spec.swift_version = "5.1"
  spec.source       = { :https => "https://github.com/SunilChowdarySirimalla/BDSDK_iOS_Package/blob/main/BrightDiagnostics.xcframework.zip"}
  spec.vendored_frameworks = "BrightDiagnostics.xcframework"
  
end