package com.rn.salesforce.chat;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;
import com.salesforce.android.chat.core.ChatConfiguration;
import com.salesforce.android.chat.core.SessionStateListener;
import com.salesforce.android.chat.core.model.ChatEndReason;
import com.salesforce.android.chat.core.model.ChatEntity;
import com.salesforce.android.chat.core.model.ChatEntityField;
import com.salesforce.android.chat.core.model.ChatSessionState;
import com.salesforce.android.chat.core.model.ChatUserData;
import com.salesforce.android.chat.ui.ChatUI;
import com.salesforce.android.chat.ui.ChatUIClient;
import com.salesforce.android.chat.ui.ChatUIConfiguration;
import com.salesforce.android.chat.ui.model.QueueStyle;
import com.salesforce.android.service.common.utilities.control.Async;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class RNSalesforceChatModule extends ReactContextBaseJavaModule implements SessionStateListener {

	private final String ChatSessionStateChanged = "ChatSessionStateChanged";
	private final String ChatSessionEnd = "ChatSessionEnd";

	private final String Connecting = "Connecting";
	private final String Queued = "Queued";
	private final String Connected = "Connected";
	private final String Ending = "Ending";
	private final String Disconnected = "Disconnected";

	private final String EndReasonUser = "EndReasonUser";
	private final String EndReasonAgent = "EndReasonAgent";
	private final String EndReasonNoAgentsAvailable = "EndReasonNoAgentsAvailable";
	private final String EndReasonTimeout = "EndReasonTimeout";
	private final String EndReasonSessionError = "EndReasonSessionError";

	private final ReactApplicationContext reactContext;
	private final Map<String, ChatUserData> chatUserDataMap;
	private final Map<String, ChatEntityField> chatEntityFieldMap;
	private final List<ChatEntity> chatEntityList;

	private ChatUIConfiguration chatUiConfiguration;

	public RNSalesforceChatModule(ReactApplicationContext reactContext) {
		super(reactContext);
		this.reactContext = reactContext;
		chatUserDataMap = new HashMap<>();
		chatEntityFieldMap = new HashMap<>();
		chatEntityList = new ArrayList<>();
	}

	@Override
	public String getName() {
		return "RNSalesforceChat";
	}

	@Override
	public Map<String, Object> getConstants() {
		final Map<String, Object> constants = new HashMap<>();
		constants.put(ChatSessionStateChanged, ChatSessionStateChanged);
		constants.put(ChatSessionEnd, ChatSessionEnd);
		constants.put(Connecting, Connecting);
		constants.put(Queued, Queued);
		constants.put(Connected, Connected);
		constants.put(Ending, Ending);
		constants.put(Disconnected, Disconnected);
		constants.put(EndReasonUser, EndReasonUser);
		constants.put(EndReasonAgent, EndReasonAgent);
		constants.put(EndReasonNoAgentsAvailable, EndReasonNoAgentsAvailable);
		constants.put(EndReasonTimeout, EndReasonTimeout);
		constants.put(EndReasonSessionError, EndReasonSessionError);
		return constants;
	}

	@ReactMethod
	public void createPreChatData(String agentLabel, @Nullable String value, Boolean isDisplayedToAgent) {
		if (value != null) {
			chatUserDataMap.put(agentLabel, new ChatUserData(agentLabel, value, isDisplayedToAgent));
		} else {
			chatUserDataMap.put(agentLabel, new ChatUserData(agentLabel, isDisplayedToAgent));
		}
	}

	@ReactMethod
	public void createEntityField(String objectFieldName, Boolean doCreate, Boolean doFind, Boolean isExactMatch, @Nullable String keyChatUserDataToMap) {
		if (chatUserDataMap.containsKey(keyChatUserDataToMap)) {
			chatEntityFieldMap.put(objectFieldName, new ChatEntityField.Builder()
					.doCreate(doCreate)
					.doFind(doFind)
					.isExactMatch(isExactMatch)
					.build(objectFieldName, Objects.requireNonNull(chatUserDataMap.get(keyChatUserDataToMap)))
			);
		}
	}

	@ReactMethod
	public void createEntity(String objectType, @Nullable String linkToTranscriptField, Boolean showOnCreate, @Nullable ReadableArray keysEntityFieldToMap) {
		ChatEntity entity;

		if (linkToTranscriptField != null) {
			entity = new ChatEntity.Builder()
					.linkToTranscriptField(linkToTranscriptField)
					.showOnCreate(showOnCreate)
					.build(objectType);
		} else  {
			entity = new ChatEntity.Builder()
					.showOnCreate(showOnCreate)
					.build(objectType);
		}

		if (keysEntityFieldToMap != null) {
			for (int i = 0; i < keysEntityFieldToMap.size(); i++) {
				String key = keysEntityFieldToMap.getString(i);
				if (chatEntityFieldMap.containsKey(key)) {
					entity.getChatEntityFields().add(chatEntityFieldMap.get(key));
				}
			}
		}

		chatEntityList.add(entity);
	}

	@ReactMethod
	public void configureChat(String orgId, String buttonId, String deploymentId, String liveAgentPod, @Nullable String visitorName) {
		ChatConfiguration.Builder chatConfigurationBuilder = new ChatConfiguration.Builder(orgId, buttonId, deploymentId, liveAgentPod);

		if (visitorName != null) chatConfigurationBuilder.visitorName(visitorName);

		ChatConfiguration chatConfiguration = chatConfigurationBuilder
				.chatUserData(new ArrayList<>(chatUserDataMap.values()))
				.chatEntities(chatEntityList)
				.build();

		chatUiConfiguration = new ChatUIConfiguration.Builder()
				.chatConfiguration(chatConfiguration)
				.queueStyle(QueueStyle.Position)
				.defaultToMinimized(false)
				.disablePreChatView(true)
				.build();
	}

	@ReactMethod
	public void openChat(final Callback errorCallback) {
		if (chatUiConfiguration == null) {
			errorCallback.invoke("error - chat not configured");
			return;
		}

		ChatUI.configure(chatUiConfiguration)
				.createClient(reactContext)
				.onResult(new Async.ResultHandler<ChatUIClient>() {
					@Override
					public void handleResult(Async<?> operation, @NonNull ChatUIClient chatUIClient) {
						chatUIClient.startChatSession(RNSalesforceChatModule.this.getCurrentActivity());
						chatUIClient.addSessionStateListener(RNSalesforceChatModule.this);
					}
				}).onError(new Async.ErrorHandler() {
			        @Override
			        public void handleError(Async<?> async, @NonNull Throwable throwable) {
                        errorCallback.invoke(String.format("%s %s", "error -", throwable.getLocalizedMessage()));
			        }
		        });
	}

	@Override
	public void onSessionStateChange(ChatSessionState chatSessionState) {
		String state;

		switch (chatSessionState) {
			case Initializing:
				state = Connecting;
				break;
			case InQueue:
				state = Queued;
				break;
			case Connected:
				state = Connected;
				break;
			case Ending:
				state = Ending;
				break;
			default:
				state = Disconnected;
				break;
		}

		WritableMap params = Arguments.createMap();
		params.putString("state", state);

		reactContext.getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
				.emit(ChatSessionStateChanged, params);
	}

	@Override
	public void onSessionEnded(ChatEndReason chatEndReason) {

		String endReason;

		switch (chatEndReason) {
			case EndedByClient:
				endReason = EndReasonUser;
				break;
			case EndedByAgent:
				endReason = EndReasonAgent;
				break;
			case NoAgentsAvailable:
				endReason = EndReasonNoAgentsAvailable;
				break;
			case LiveAgentTimeout:
				endReason = EndReasonTimeout;
				break;
			default:
				endReason = EndReasonSessionError;
				break;
		}

		WritableMap params = Arguments.createMap();
		params.putString("reason", endReason);

		reactContext.getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
				.emit(ChatSessionEnd, params);
	}
}

