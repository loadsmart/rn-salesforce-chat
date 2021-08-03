
# rn-salesforce-chat

## Getting started

`$ npm install @loadsmart/rn-salesforce-chat --save` or `$ yarn add @loadsmart/rn-salesforce-chat` if yarn is used.

### Mostly automatic installation

On your project root run:

`$ react-native link @loadsmart/rn-salesforce-chat`

Add the following maven repository to your project's `build.gradle` file:

```java
allprojects {
  repositories {
    maven {
      url 'https://s3.amazonaws.com/salesforcesos.com/android/maven/release'
    }
  }
}
```

Add the following pod sources to your project's `Podfile` file:

```js
source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/goinstant/pods-specs-public'
```

Open your ios folder and run:

`$ pod install`

That's it!

### Manual installation

#### iOS

1. On Xcode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `rn-salesforce-chat` and add `RNSalesforceChat.xcodeproj`
3. Again in the project navigator, select your project. Add `libRNSalesforceChat.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)

#### Android

1. Add the following maven repository to your project's `build.gradle` file:

    ```java
    allprojects {
      repositories {
        maven {
          url 'https://s3.amazonaws.com/salesforcesos.com/android/maven/release'
        }
      }
    }
    ```

2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':rn-salesforce-chat'
  	project(':rn-salesforce-chat').projectDir = new File(rootProject.projectDir, '../node_modules/rn-salesforce-chat/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
    implementation project(path: ':@loadsmart_rn-salesforce-chat')
  	```

4. Open `android/app/src/main/java/[...]/MainApplication.java`
  - Add `import com.rn.salesforce.chat.RNSalesforceChatPackage;` to the imports at the top of the file
  - Add `new RNSalesforceChatPackage()` to the list returned by the `getPackages()` method    

<br/>

**Note**: This library does not support **Expo**.

---

## Prepare App Submission for iOS

Before you can submit your app to the App Store, you need to strip development resources (such as unneeded architectures and header resources) from the dynamic libraries used by the Salesforce Service SDK.

Xcode doesn't automatically strip unneeded architectures from dynamic libraries, nor remove some header and utility resources. Apps that don't do this clean up are rejected from the App Store. For example, you might receive the following error:

```
ERROR ITMS-90085:
No architectures in the binary. Lipo failed to detect any architectures in the bundle executable.
```

You can resolve this problem by using the script provided in the Salesforce ServiceCore framework that automatically strips unneeded architectures from the dynamic libraries and then re-signs them. To use this script:

1. Select Build Phases for your project target.
2. Create a Run Script phase to run the script.
3. Copy the script bellow and paste on the script box:
```sh
if [ "${CONFIGURATION}" = "Release" ]; then
    $PODS_ROOT/ServiceSDK/Frameworks/ServiceCore.xcframework/ios-arm64/ServiceCore.framework/prepare-framework
else
    $PODS_ROOT/ServiceSDK/Frameworks/ServiceCore.xcframework/ios-x86_64-simulator/ServiceCore.framework/prepare-framework
fi;
```

This build phase **must occur after the link phase and all embed phases**. If you're using CocoaPods, make sure to put this script after the "[CP] Embed Pods Frameworks" phase.

---

## Usage example
```js
import { SalesforceChatAPI } from '@loadsmart/rn-salesforce-chat'

export default async function startSalesforceChat() {

  const salesforceApi = new SalesforceChatAPI()

  const firstName = 'First Name'
  const lastName = 'Last Name'
		
  // creating pre chat data objects:
  const createPreChatData = async () => {
    salesforceApi.createPreChatData({
      agentLabel: firstName,
      value: "Some First Name",
      isDisplayedToAgent: true,
      transcriptFields: ["some transcript field"]
    })

    salesforceApi.createPreChatData({
      agentLabel: lastName,
      value: "Some Last Name",
      isDisplayedToAgent: true,
      transcriptFields: ["some transcript field"]
    })
  }

  // creating entity field objects:
  const createEntityFields = async () => {
    salesforceApi.createEntityField({
      objectFieldName: firstName,
      doCreate: false,
      doFind: true,
      isExactMatch: false,
      keyChatUserDataToMap: firstName,
    })

    salesforceApi.createEntityField({
      objectFieldName: lastName,
      doCreate: false,
      doFind: true,
      isExactMatch: false,
      keyChatUserDataToMap: lastName,
    })
  }

  // creating an entity object:
  const createEntities = async () => {
    salesforceApi.createEntity({
      objectType: 'Contact',
      linkToTranscriptField: 'ContactId',
      showOnCreate: true,
      keysEntityFieldToMap: [firstName, lastName],
    })
  }

  /* configure chat
    Be extra careful in this step, correctly applying the right configuration. 
    Wrong configuration can lead to unexpected crashes and the Salesforce SDK 
    may not provide any warnings or error messages for those. 
  */
  const configureChat = async () => {
    salesforceApi.configureChat({
      orgId: "ORG_ID",
      buttonId: "BUTTON_ID",
      deploymentId: "DEPLOYMENT_ID",
      liveAgentPod: "LIVE_AGENT_POD",
      visitorName: "Some Visitor Name"
    })
  }

  // start chat
  const startChat = async () => {
    salesforceApi.openChat((errorMessage: string) => {
      // error handling
      console.debug('got error', errorMessage)
    }, 
    () => {
      // success handling
      console.debug('got success')
    })
  }
 
  await createUserData()
  await createEntityFields()
  await createEntities()
  await configureChat()
  await startChat()
}
```
---

## Handling events

There are two types of events that are sent: `ChatSessionStateChanged` and `ChatSessionEnd`.

Events for `ChatSessionStateChanged`

- **Connecting** - A connection with Live Agent servers is being established.
- **Queued** - A connection has been established, but queueing for next available agent.
- **Connected** - Connected with an agent to facilitate a chat session.
- **Ending** - Session is in the process of cleaning up network connections and ending.
- **Disconnected** - No active session. There will be no outgoing/incoming chat traffic.

Events for `ChatSessionEnd`

- **EndReasonUser** - Session was ended due to user interaction.
- **EndReasonAgent** - Session was ended remotely by the agent.
- **EndReasonNoAgentsAvailable** - Session was ended as a result of no agents being available.
- **EndReasonTimeout** - Session was ended due to a network disruption resulting in a timeout.
- **EndReasonSessionError** - Session was ended as the result of a fatal error.


Usage example:

```js
import { NativeEventEmitter, NativeModules } from 'react-native'

...

const salesforceChat = NativeModules.RNSalesforceChat

const eventEmitter = new NativeEventEmitter(NativeModules.RNSalesforceChat)

eventEmitter.removeAllListeners(salesforceChat.ChatSessionStateChanged)
eventEmitter.removeAllListeners(salesforceChat.ChatSessionEnd)

eventEmitter.addListener(salesforceChat.ChatSessionStateChanged, event => {
  // custom code
  console.debug('received ChatSessionState event', event.state)
})

eventEmitter.addListener(salesforceChat.ChatSessionEnd, event => {
  // custom code
  console.debug('received ChatEndReason event state', event.reason)
})
```
---

## Styling

Chat styling can be made directly in the native modules of your app. You can use these official Salesforce links ([Android](https://developer.salesforce.com/docs/atlas.en-us.noversion.service_sdk_android.meta/service_sdk_android/android_customization.htm#ess_ui_customization) - [iOS](https://developer.salesforce.com/docs/atlas.en-us.noversion.service_sdk_ios.meta/service_sdk_ios/servicesdk_ui_customization.htm#ess_ui_customization)) to read more about it.

---

## License

[MIT](./LICENSE)

---

## Contributing

### RFCs

If you want to submit a "Request for comments" proposal, branch out from `master` (i.e.: `rfc/my-feature`) copy `0000-template.md` to `rfc/0000-my-feature.md` (where 'my-feature' is descriptive. don't assign an RFC number yet), fill in the RFC and submit a PR.

If your RFC gets approved, you can then merge the PR to `master`.
