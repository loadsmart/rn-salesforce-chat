import { NativeModules } from "react-native";
import SalesforceChatAPI from "../salesforceChatAPI";

const mockCreatePreChatData = jest.fn();
const mockCreateEntityField = jest.fn();
const mockCreateEntity = jest.fn();
const mockConfigureChat = jest.fn();
const mockOpenChat = jest.fn();

NativeModules.RNSalesforceChat = {
  createPreChatData: mockCreatePreChatData,
  createEntityField: mockCreateEntityField,
  createEntity: mockCreateEntity,
  configureChat: mockConfigureChat,
  openChat: mockOpenChat,
};

const salesforceChatAPI = new SalesforceChatAPI();

let mockParamCreatePreChatData;
let mockParamCreateEntityField;
let mockParamCreateEntity;
let mockParamConfigureChat;

describe("SalesforceChatAPI", () => {
  beforeEach(() => {
    mockParamCreatePreChatData = {
      agentLabel: "someLabel",
      value: "someValue",
      isDisplayedToAgent: true,
      transcriptFields: ["someTranscriptField"]
    };

    mockParamCreateEntityField = {
      objectFieldName: "someObjectFieldName",
      doCreate: false,
      doFind: true,
      isExactMatch: true,
      keyChatUserDataToMap: ["someKeyField"],
    };

    mockParamCreateEntity = {
      objectType: "someObjectType",
      linkToTranscriptField: "someTranscriptField",
      showOnCreate: false,
      keysEntityFieldToMap: ["someKeyField"],
    };

    mockParamConfigureChat = {
      orgId: "someOrgId",
      buttonId: "someButtonId",
      deploymentId: "someDeploymentId",
      liveAgentPod: "someLiveAgentPod",
      visitorName: "Some Name",
    };
  });

  describe("createPreChatData", () => {
    it("calls createPreChatData with correct parameters", async () => {
      await salesforceChatAPI.createPreChatData(mockParamCreatePreChatData);

      expect(mockCreatePreChatData).toHaveBeenCalledWith(
        "someLabel",
        "someValue",
        true,
        ["someTranscriptField"]
      );

      mockParamCreatePreChatData = {
        agentLabel: "someLabel",
        isDisplayedToAgent: true,
        transcriptFields: ["someTranscriptField"]
      }

      await salesforceChatAPI.createPreChatData(mockParamCreatePreChatData);

      expect(mockCreatePreChatData).toHaveBeenCalledWith(
        "someLabel",
        null,
        true,
        ["someTranscriptField"]
      );

      mockParamCreatePreChatData = {
        agentLabel: "someLabel",
        value: "someValue",
        isDisplayedToAgent: true,
      }

      await salesforceChatAPI.createPreChatData(mockParamCreatePreChatData);

      expect(mockCreatePreChatData).toHaveBeenCalledWith(
        "someLabel",
        "someValue",
        true,
        null,
      );
    });

    it("throws an error when calling createPreChatData with undefined agentLabel", async () => {
      mockParamCreatePreChatData.agentLabel = undefined;

      await expect(
        salesforceChatAPI.createPreChatData(mockParamCreatePreChatData)
      ).rejects.toThrowError(new Error("required field agentLabel"));
    });

    it("throws an error when calling createPreChatData with null agentLabel", async () => {
      mockParamCreatePreChatData.agentLabel = null;

      await expect(
        salesforceChatAPI.createPreChatData(mockParamCreatePreChatData)
      ).rejects.toThrowError(new Error("required field agentLabel"));
    });

    it("throws an error when calling createPreChatData with undefined isDisplayedToAgent", async () => {
      mockParamCreatePreChatData.isDisplayedToAgent = undefined;

      await expect(
        salesforceChatAPI.createPreChatData(mockParamCreatePreChatData)
      ).rejects.toThrowError(new Error("required field isDisplayedToAgent"));
    });

    it("throws an error when calling createPreChatData with null isDisplayedToAgent", async () => {
      mockParamCreatePreChatData.isDisplayedToAgent = null;

      await expect(
        salesforceChatAPI.createPreChatData(mockParamCreatePreChatData)
      ).rejects.toThrowError(new Error("required field isDisplayedToAgent"));
    });
  });

  describe("createEntityField", () => {
    it("calls createEntityField with correct parameters", async () => {
      await salesforceChatAPI.createEntityField(mockParamCreateEntityField);

      expect(mockCreateEntityField).toHaveBeenCalledWith(
        "someObjectFieldName",
        true,
        false,
        true,
        ["someKeyField"]
      );

      mockParamCreateEntityField = {
        objectFieldName: "someObjectFieldName",
        doFind: true,
        doCreate: false,
        isExactMatch: true
      }

      await salesforceChatAPI.createEntityField(mockParamCreateEntityField);

      expect(mockCreateEntityField).toHaveBeenCalledWith(
        "someObjectFieldName",
        true,
        false,
        true,
        null
      );
    });

    it("throws an error when calling createEntityField with undefined objectFieldName", async () => {
      mockParamCreateEntityField.objectFieldName = undefined;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field objectFieldName"));
    });

    it("throws an error when calling createEntityField with null objectFieldName", async () => {
      mockParamCreateEntityField.objectFieldName = null;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field objectFieldName"));
    });

    it("throws an error when calling createEntityField with undefined doFind", async () => {
      mockParamCreateEntityField.doFind = undefined;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field doFind"));
    });

    it("throws an error when calling createEntityField with null doFind", async () => {
      mockParamCreateEntityField.doFind = null;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field doFind"));
    });

    it("throws an error when calling createEntityField with undefined doCreate", async () => {
      mockParamCreateEntityField.doCreate = undefined;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field doCreate"));
    });

    it("throws an error when calling createEntityField with null doCreate", async () => {
      mockParamCreateEntityField.doCreate = null;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field doCreate"));
    });

    it("throws an error when calling createEntityField with undefined isExactMatch", async () => {
      mockParamCreateEntityField.isExactMatch = undefined;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field isExactMatch"));
    });

    it("throws an error when calling createEntityField with null isExactMatch", async () => {
      mockParamCreateEntityField.isExactMatch = null;

      await expect(
        salesforceChatAPI.createEntityField(mockParamCreateEntityField)
      ).rejects.toThrowError(new Error("required field isExactMatch"));
    });
  });

  describe("createEntity", () => {
    it("calls createEntity with correct parameters", async () => {
      await salesforceChatAPI.createEntity(mockParamCreateEntity);

      expect(mockCreateEntity).toHaveBeenCalledWith(
        "someObjectType",
        "someTranscriptField",
        false,
        ["someKeyField"]
      );

      mockParamCreateEntity = {
        objectType: "someObjectType",
        showOnCreate: false
      }

      await salesforceChatAPI.createEntity(mockParamCreateEntity);

       expect(mockCreateEntity).toHaveBeenCalledWith(
        "someObjectType",
        null,
        false,
        null
      );
    });

    it("throws an error when calling createEntity with undefined objectType", async () => {
      mockParamCreateEntity.objectType = undefined;

      await expect(
        salesforceChatAPI.createEntity(mockParamCreateEntity)
      ).rejects.toThrowError(new Error("required field objectType"));
    });

    it("throws an error when calling createEntity with null objectType", async () => {
      mockParamCreateEntity.objectType = null;

      await expect(
        salesforceChatAPI.createEntity(mockParamCreateEntity)
      ).rejects.toThrowError(new Error("required field objectType"));
    });

    it("throws an error when calling createEntity with undefined showOnCreate", async () => {
      mockParamCreateEntity.showOnCreate = undefined;

      await expect(
        salesforceChatAPI.createEntity(mockParamCreateEntity)
      ).rejects.toThrowError(new Error("required field showOnCreate"));
    });

    it("throws an error when calling createEntity with null showOnCreate", async () => {
      mockParamCreateEntity.showOnCreate = null;

      await expect(
        salesforceChatAPI.createEntity(mockParamCreateEntity)
      ).rejects.toThrowError(new Error("required field showOnCreate"));
    });
  });

  describe("configureChat", () => {
    it("calls configureChat with correct parameters", async () => {
      await salesforceChatAPI.configureChat(mockParamConfigureChat);

      expect(mockConfigureChat).toHaveBeenCalledWith(
        "someOrgId",
        "someButtonId",
        "someDeploymentId",
        "someLiveAgentPod",
        "Some Name"
      );

      mockParamConfigureChat = {
        orgId: "someOrgId",
        buttonId: "someButtonId",
        deploymentId: "someDeploymentId",
        liveAgentPod: "someLiveAgentPod",
      }

      await salesforceChatAPI.configureChat(mockParamConfigureChat);

      expect(mockConfigureChat).toHaveBeenCalledWith(
        "someOrgId",
        "someButtonId",
        "someDeploymentId",
        "someLiveAgentPod",
        undefined
      );
    });
    
    it("throws an error when calling configureChat with undefined orgId", async () => {
      mockParamConfigureChat.orgId = undefined;

      await expect(
        salesforceChatAPI.configureChat(mockParamConfigureChat)
      ).rejects.toThrowError(new Error("required field orgId"));
    });

    it("throws an error when calling configureChat with undefined buttonId", async () => {
      mockParamConfigureChat.buttonId = undefined;

      await expect(
        salesforceChatAPI.configureChat(mockParamConfigureChat)
      ).rejects.toThrowError(new Error("required field buttonId"));
    });

    it("throws an error when calling configureChat with undefined deploymentId", async () => {
      mockParamConfigureChat.deploymentId = undefined;

      await expect(
        salesforceChatAPI.configureChat(mockParamConfigureChat)
      ).rejects.toThrowError(new Error("required field deploymentId"));
    });

    it("throws an error when calling configureChat with undefined liveAgentPod", async () => {
      mockParamConfigureChat.liveAgentPod = undefined;

      await expect(
        salesforceChatAPI.configureChat(mockParamConfigureChat)
      ).rejects.toThrowError(new Error("required field liveAgentPod"));
    });
  });

  describe("openChat", () => {
    it("calls openChat with the correct callback params", async () => {
      const mockFailureCallback = () => {};
      const mockSuccessCallback = () => {};

      await salesforceChatAPI.openChat(mockFailureCallback, mockSuccessCallback);

      expect(mockOpenChat).toHaveBeenCalledWith(mockFailureCallback, mockSuccessCallback);
    });
  });
});
