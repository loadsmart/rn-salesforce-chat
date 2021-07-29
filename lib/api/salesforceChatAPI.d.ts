import { PreChatData } from "./interfaces/PreChatData";
import { ChatEntityField } from "./interfaces/ChatEntityField";
import { ChatEntity } from "./interfaces/ChatEntity";
import { ChatConfig } from "./interfaces/ChatConfig";

export default class SalesforceChatAPI {
  createPreChatData(preChatData: PreChatData): Promise<void>;
  createEntityField(chatEntityField: ChatEntityField): Promise<void>;
  createEntity(chatEntity: ChatEntity): Promise<void>;
  configureChat(chatConfig: ChatConfig): Promise<void>;
  openChat(errorCallback: (errorMessage: string) => void): Promise<void>;
}
