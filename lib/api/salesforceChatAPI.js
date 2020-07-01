import { NativeModules } from "react-native";

export default class SalesforceChatAPI {
  constructor() {
    this.salesforceChat = NativeModules.RNSalesforceChat;
  }

  throwRequiredFieldError(field) {
    throw new Error(`required field ${field}`);
  }

  async createUserData({ agentLabel, value, isDisplayedToAgent }) {
    if (!agentLabel) this.throwRequiredFieldError("agentLabel");
    if (isDisplayedToAgent === undefined)
      this.throwRequiredFieldError("isDisplayedToAgent");

    this.salesforceChat.createPreChatData(
      agentLabel,
      value,
      isDisplayedToAgent
    );
  }

  async createEntityField({
    objectFieldName,
    doFind,
    doCreate,
    isExactMatch,
    keyChatUserDataToMap,
  }) {
    if (!objectFieldName) this.throwRequiredFieldError("objectFieldName");
    if (doFind === undefined) this.throwRequiredFieldError("doFind");
    if (doCreate === undefined) this.throwRequiredFieldError("doCreate");
    if (isExactMatch === undefined)
      this.throwRequiredFieldError("isExactMatch");

    this.salesforceChat.createEntityField(
      objectFieldName,
      doFind,
      doCreate,
      isExactMatch,
      keyChatUserDataToMap
    );
  }

  async createEntity({
    objectType,
    linkToTranscriptField,
    showOnCreate,
    keysEntityFieldToMap,
  }) {
    if (!objectType) this.throwRequiredFieldError("objectType");
    if (showOnCreate === undefined)
      this.throwRequiredFieldError("showOnCreate");

    this.salesforceChat.createEntity(
      objectType,
      linkToTranscriptField,
      showOnCreate,
      keysEntityFieldToMap
    );
  }

  async configureChat({ orgId, buttonId, deploymentId, liveAgentPod }) {
    if (!orgId) this.throwRequiredFieldError("orgId");
    if (!buttonId) this.throwRequiredFieldError("buttonId");
    if (!deploymentId) this.throwRequiredFieldError("deploymentId");
    if (!liveAgentPod) this.throwRequiredFieldError("liveAgentPod");

    this.salesforceChat.configureChat(
      orgId,
      buttonId,
      deploymentId,
      liveAgentPod
    );
  }

  async openChat(errorCallback) {
    this.salesforceChat.openChat(errorCallback);
  }
}
