// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "BDSDK_iOS",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "BDSDK_iOS",
            targets: ["BDSDK_iOS"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
         .package(url: "git@github.com:SunilChowdarySirimalla/BDSDK.git", .exact("2.0")
    ],
    targets: [
//         // Targets are the basic building blocks of a package. A target can define a module or a test suite.
//         // Targets can depend on other targets in this package, and on products in packages this package depends on.
//         //.package(url: "git@github.com:SunilChowdarySirimalla/BDSDK.git", .exact("1.0")
//         .binaryTarget(name: "BDSDK_iOS",
//                                   url: "git@github.com:SunilChowdarySirimalla/BDSDK.git",
//                                   checksum: "37d3e814f995b2762ca9ae3ac2d058933c479e8c1098ee079273d8ea2e665f93"),
    ]
)
