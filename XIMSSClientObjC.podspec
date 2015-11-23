Pod::Spec.new do |s|
  s.name         = "XIMSSClientObjC"
  s.version      = "2015.09.20"
  s.summary      = "CommuniGate XIMSS Client SDK"

  s.homepage     = "https://www.communigate.com/XIMSSClient/Guide/default.html"
  s.license      = { :type => "Commercial", :text => "Copyright 1991-2015 Stalker Software, Inc. All Rights Reserved." }
  s.author       = { "Stalker Software, Inc." => "support@communigate.com" }

  s.source       = { :git => "https://github.com/yarrcc/XIMSSClientObjC.git" , :commit => "d992f3b2434b3782b8bbb32f9d694b523e80b983" }

  s.platform     = :ios, '8.0'
  s.requires_arc = true
     
  s.source_files         = "*.{m,h}"
  s.public_header_files  = "*.h"
    
  s.ios.vendored_libraries = "libXIMSSiOS.a"
    
  s.xcconfig = { :OTHER_LDFLAGS => "-ObjC" }
      
  s.prepare_command = <<-CMD
    lipo -create iphoneos/libXIMSSiOS.a iphonesimulator/libXIMSSiOS.a -o libXIMSSiOS.a
    sed -i '' 's/if defined(TARGET_OS_MAC)/if !defined(TARGET_OS_IPHONE) \&\& !defined(TARGET_IPHONE_SIMULATOR)/g' XIMSSSession.h
    touch ForceFrameworkBuild.m
  CMD
end