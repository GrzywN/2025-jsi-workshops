import {TurboModule, TurboModuleRegistry} from 'react-native';

interface EmptyObject {}

export interface Spec extends TurboModule {
  readonly install: () => void;
  readonly task15: (simpleObject: EmptyObject) => void;
}

export default TurboModuleRegistry.getEnforcing<Spec>(
  'NativeJSIWorkshopsModule',
);
