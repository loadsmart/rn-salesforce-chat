import { NativeModules } from "react-native";

export default class SalesforceChatAPI {
  constructor() {
    this.salesforceChat = NativeModules.RNSalesforceChat;
  }

  async createUserData(chatUserData) {
    this.salesforceChat.createPreChatData(
      chatUserData.agentLabel,
      chatUserData.value,
      chatUserData.isDisplayedToAgent
    );
  }

  async createEntityField(chatEntityField) {
    this.salesforceChat.createEntityField(
      chatEntityField.objectFieldName,
      chatEntityField.doFind,
      chatEntityField.doCreate,
      chatEntityField.isExactMatch,
      chatEntityField.keyChatUserDataToMap
    );
  }

  async createEntity(chatEntity) {
    this.salesforceChat.createEntity(
      chatEntity.objectType,
      chatEntity.linkToTranscriptField,
      chatEntity.showOnCreate,
      chatEntity.keysEntityFieldToMap
    );
  }

  async configureChat(chatConfig) {
    this.salesforceChat.configureChat(
      chatConfig.orgId,
      chatConfig.buttonId,
      chatConfig.deploymentId,
      chatConfig.liveAgentPod
    );
  }

  async openChat(errorCallback) {
    this.salesforceChat.openChat(errorCallback);
  }
}
