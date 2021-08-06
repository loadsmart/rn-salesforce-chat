export interface ChatEntityField {
  objectFieldName: string;
  doCreate: boolean;
  doFind: boolean;
  isExactMatch: boolean;
  preChatDataKeyToMap?: string;
  entityFieldKey: string;
}
