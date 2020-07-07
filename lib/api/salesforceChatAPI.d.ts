import { ChatUserData } from "./interfaces/ChatUserData";
import { ChatEntityField } from "./interfaces/ChatEntityField";
import { ChatEntity } from "./interfaces/ChatEntity";
import { ChatConfig } from "./interfaces/ChatConfig";

export default class SalesforceChatAPI {
  createUserData(chatUserData: ChatUserData): Promise<void>;
  createEntityField(chatEntityField: ChatEntityField): Promise<void>;
  createEntity(chatEntity: ChatEntity): Promise<void>;
  configureChat(chatConfig: ChatConfig): Promise<void>;
  openChat(errorCallback: (errorMessage: string) => void): Promise<void>;
}
