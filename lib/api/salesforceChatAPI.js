import { NativeModules, Platform } from "react-native";

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

  async createPreChatData({
    agentLabel,
    value,
    isDisplayedToAgent,
    transcriptFields,
    preChatDataKey,
  }) {
    if (!agentLabel) {
      this.throwRequiredFieldError("agentLabel");
    }
    if (this.isInvalidBooleanParam(isDisplayedToAgent)) {
      this.throwRequiredFieldError("isDisplayedToAgent");
    }
    if (!preChatDataKey) {
      this.throwRequiredFieldError("preChatDataKey");
    }

    if (!value) value = null;
    if (!transcriptFields) transcriptFields = null;

    this.salesforceChat.createPreChatData(
      agentLabel,
      value,
      isDisplayedToAgent,
      transcriptFields,
      preChatDataKey
    );
  }

  async createEntityField({
    objectFieldName,
    doCreate,
    doFind,
    isExactMatch,
    preChatDataKeyToMap,
    entityFieldKey,
  }) {
    if (!objectFieldName) this.throwRequiredFieldError("objectFieldName");

    if (this.isInvalidBooleanParam(doCreate)) {
      this.throwRequiredFieldError("doCreate");
    }
    if (this.isInvalidBooleanParam(doFind)) {
      this.throwRequiredFieldError("doFind");
    }
    if (this.isInvalidBooleanParam(isExactMatch)) {
      this.throwRequiredFieldError("isExactMatch");
    }
    if (!entityFieldKey) {
      this.throwRequiredFieldError("entityFieldKey");
    }

    if (!preChatDataKeyToMap) preChatDataKeyToMap = null;

    this.salesforceChat.createEntityField(
      objectFieldName,
      doCreate,
      doFind,
      isExactMatch,
      preChatDataKeyToMap,
      entityFieldKey
    );
  }

  async createEntity({
    objectType,
    linkToTranscriptField,
    showOnCreate,
    entityFieldKeysToMap,
  }) {
    if (!objectType) this.throwRequiredFieldError("objectType");
    if (this.isInvalidBooleanParam(showOnCreate)) {
      this.throwRequiredFieldError("showOnCreate");
    }

    if (!linkToTranscriptField) linkToTranscriptField = null;
    if (!entityFieldKeysToMap) entityFieldKeysToMap = null;

    this.salesforceChat.createEntity(
      objectType,
      linkToTranscriptField,
      showOnCreate,
      entityFieldKeysToMap
    );
  }

  async configureChat({
    orgId,
    buttonId,
    deploymentId,
    liveAgentPod,
    visitorName,
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

  async openChat(failureCallback, successCallback) {
    this.salesforceChat.openChat(failureCallback, successCallback);
  }

  async setupChatColorIOS(
    redValue,
    greenValue,
    blueValue,
    alphaValue,
    colorToken
  ) {
    if (Platform.OS === "ios") {
      this.salesforceChat.setupChatColorIOS(
        redValue,
        greenValue,
        blueValue,
        alphaValue,
        colorToken
      );
    } else {
      throw new Error(
        `trying to use iOS method setupChatColorIOS for platform ${Platform.OS}`
      );
    }
  }
}
