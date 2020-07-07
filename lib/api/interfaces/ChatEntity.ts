export interface ChatEntity {
  objectType: string;
  linkToTranscriptField: string | null;
  showOnCreate: boolean;
  keysEntityFieldToMap: string[] | null;
}
