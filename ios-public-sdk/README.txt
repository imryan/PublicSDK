Public SDK Software Release

CONTENTS

- HelloGoTenna/        - source code for sample application for using the SDK
- GoTennaSDK.framework - compiled goTenna SDK that can be imported into any iOS codebase
- GoTennaSDKDocs/html  - start point for viewing the SDK documentation

Requires iOS 9.0+

INSTALLATION OF iOS SDK
 
To install, you must import the .framework file into your Xcode project.
You can do this by dragging the .framework file into General tab of your target, drag it into the ‘Embedded Binaries’ section so it appears in both ‘Embedded Binaries’ and ‘Linked Frameworks and Libraries’.
You must also make sure Enable Bitcode in the build settings is set to NO. The .framework should warn you if you forget to do this.
Lastly, in build settings, set 'Allow Non-modular Includes in Framework Modules' to Yes.

This can only be run for a device, not for a simulator.

See the HelloGoTenna project for an example of this.
 
CONNECTING/DISCONNECTING
 
You application pairs with a goTenna over Bluetooth LE. Confirm your hardware has BTLE capabilities before beginning.
 
GIDs
 
A goTenna ID is the unique identifier that your goTenna will use to identify itself  and others will use to send you messages. Before you can start sending/receiving messages, a goTenna needs to have this value set. The example app can be referenced for this. You need to call [[GTCommandCenter shared] setgoTennaGID:]. GIDs are managed completely through the GTCommandCenter class. See class documentation and the example app for reference.
 
BASICS/FAQs
 
The goTenna SDK allows an app developer to easily get up and running using a network of goTennas. At it's core, you'll be able to:
- Send messages to every other goTenna in range (broadcasting).
- Send messages to another single goTenna.
- Create a group of specific users and message everyone in this group.
 
Messages may be optionally encrypted using default functionality provided by the SDK.
 
MESSAGES

- Outgoing messages are limited in size to 236 bytes
- There is currently a limit of sending only 5 messages per minute. This is to prevent developers from flooding the radio channels with their own app's content, potentially blocking other apps from communicating.
 
Message Types

 * One-to-One
    - sending a message to one other user only
    - you will receive acknowledgement of receipt
 * Broadcast
    - sending a message to all users within ranges
    - this uses the reserved GID '1111111111'
    - on receiving this type of message you can recognize it as a broadcast based on the GID '1111111111'
    - sender does not receive any acknowledgements of receipt by receivers
 * Group
    - sending a message to group created with a finite number of members (< 10)
    - see example app for creating a group and being notified of being added to a group
    - sender does not receive any acknowledgements of receipt by receivers

MESH SDK UPDATE NOTES

How do I connect to a goTenna Mesh vs. V1 goTenna?

- Previously, to start the goTenna pairing proces, you would call [[GTPairingManager shared] initiateScanningConnect].
Now there is an additional function [[BluetoothConnectionManager shared] setDevice:(GTDeviceType)], and in this function you can specify GTDeviceTypeGoTenna or GTDeviceTypeMesh.

IMPORTANT DETAILS ON OPERATING REGIONS

The goTenna Mesh was created to operate according to FCC Regulations on a per region basis. This means that in order to use the goTenna Mesh properly, you must determine which region you are in and tell the goTenna so that it can use the proper transmit frequencies designated for that region.

Currently supported regions are: 
    NORTH_AMERICA,
    EUROPE,
    AUSTRALIA,
    NEW_ZEALAND,
    SINGAPORE.

After determining which region you are in, simply call the function [[GTCommandCenter shared] sendSetGeoRegion:RegionID onResponse:response onError:error]. This will tell the goTenna Mesh which region it is in, and it will alter its transmit frequencies accordingly.
