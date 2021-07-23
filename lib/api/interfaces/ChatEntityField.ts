export interface ChatEntityField {
  objectFieldName: string;
  doCreate: boolean;
  doFind: boolean;
  isExactMatch: boolean;
  keyChatUserDataToMap?: string;
}
