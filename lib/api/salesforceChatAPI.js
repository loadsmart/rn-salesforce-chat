import { NativeModules } from "react-native";

export default class SalesforceChatAPI {
  constructor() {
    this.salesforceChat = NativeModules.RNSalesforceChat;
  }

  throwRequiredFieldError(field) {
    throw new Error(`required field ${field}`);
  }

  isInvalidBooleanParam(param) {
    return param === undefined || param === null;
  }

  async createPreChatData({ agentLabel, value, isDisplayedToAgent, transcriptFields }) {
    
    if (!agentLabel) {
      this.throwRequiredFieldError("agentLabel");
    }
    if (this.isInvalidBooleanParam(isDisplayedToAgent)) {
      this.throwRequiredFieldError("isDisplayedToAgent");
    }

    this.salesforceChat.createPreChatData(
      agentLabel,
      value,
      isDisplayedToAgent,
      transcriptFields
    );
  }

  async createEntityField({
    objectFieldName,
    doFind,
    doCreate,
    isExactMatch,
    keyChatUserDataToMap
  }) {
    if (!objectFieldName) this.throwRequiredFieldError("objectFieldName");
    if (this.isInvalidBooleanParam(doFind)) {
      this.throwRequiredFieldError("doFind");
    }
    if (this.isInvalidBooleanParam(doCreate)) {
      this.throwRequiredFieldError("doCreate");
    }
    if (this.isInvalidBooleanParam(isExactMatch)) {
      this.throwRequiredFieldError("isExactMatch");
    }

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
    keysEntityFieldToMap
  }) {
    if (!objectType) this.throwRequiredFieldError("objectType");
    if (this.isInvalidBooleanParam(showOnCreate)) {
      this.throwRequiredFieldError("showOnCreate");
    }

    this.salesforceChat.createEntity(
      objectType,
      linkToTranscriptField,
      showOnCreate,
      keysEntityFieldToMap
    );
  }

  async configureChat({
    orgId,
    buttonId,
    deploymentId,
    liveAgentPod,
    visitorName
  }) {
    if (!orgId) this.throwRequiredFieldError("orgId");
    if (!buttonId) this.throwRequiredFieldError("buttonId");
    if (!deploymentId) this.throwRequiredFieldError("deploymentId");
    if (!liveAgentPod) this.throwRequiredFieldError("liveAgentPod");

    this.salesforceChat.configureChat(
      orgId,
      buttonId,
      deploymentId,
      liveAgentPod,
      visitorName
    );
  }

  async openChat(errorCallback) {
    this.salesforceChat.openChat(errorCallback);
  }
}
