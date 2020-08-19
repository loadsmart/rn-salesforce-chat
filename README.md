
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

Open your ios folder and run:

`$ pod install`

That's it!


**Note**: This library does not support **Expo**.

### Manual installation


#### iOS

1. On Xcode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `rn-salesforce-chat` and add `RNSalesforceChat.xcodeproj`
3. Again in the project navigator, select your project. Add `libRNSalesforceChat.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

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
    compile project(':rn-salesforce-chat')
  	```

4. Open `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.rn.salesforce.chat.RNSalesforceChatPackage;` to the imports at the top of the file
  - Add `new RNSalesforceChatPackage()` to the list returned by the `getPackages()` method    


## Usage example
```javascript
import { SalesforceChatAPI } from '@loadsmart/rn-salesforce-chat'

export default async function startSalesforceChat() {

  const salesforceApi = new SalesforceChatAPI()

  const firstName = 'First Name'
  const lastName = 'Last Name'
		
  // creating user data objects:
  const createUserData = async () => {
    salesforceApi.createUserData({
      agentLabel: firstName,
      value: "Some First Name",
      isDisplayedToAgent: true,
    })

    salesforceApi.createUserData({
      agentLabel: lastName,
      value: "Some Last Name",
      isDisplayedToAgent: true,
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

  // configure chat
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
    })
  }
 
  await createPreChatData()
  await createEntityFields()
  await createEntities()
  await configureChat()
  await startChat()
}
```

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

```javascript
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

## Styling

Chat styling can be made directly in the native modules of your app. You can use these official Salesforce links ([Android](https://developer.salesforce.com/docs/atlas.en-us.service_sdk_android.meta/service_sdk_android/android_customization.htm) - [iOS](https://developer.salesforce.com/docs/atlas.en-us.noversion.service_sdk_ios.meta/service_sdk_ios/servicesdk_ui_customization.htm)) to read more about.

## License

[MIT](./LICENSE)

## Contributing

### RFCs

If you want to submit a "Request for comments" proposal, branch out from `master` (i.e.: `rfc/my-feature`) copy `0000-template.md` to `rfc/0000-my-feature.md` (where 'my-feature' is descriptive. don't assign an RFC number yet), fill in the RFC and submit a PR.

If your RFC gets approved, you can then merge the PR to `master`.
