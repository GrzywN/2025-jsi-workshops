import * as React from 'react';

import {Button, StyleSheet, View} from 'react-native';

import NativeJSIWorkshopsModule from './specs/NativeJSIWorkshopsModule';

NativeJSIWorkshopsModule.install();

declare global {
  var answerToTheUltimateQuestionOfLifeTheUniverseAndEverything: number;
  var isWednesday: boolean;
  var workshopsName: string;
  var myAwesomeArray: number[];
  var giveMeFive: () => number;
  var sumMeThis: (a: number, b: number) => number;
  var divideMeThis: (a: number, b: number) => number;
  var reverseMeThis: (str: string) => string;
  var sumMeThisObject: (obj: {firstNum: number; lastNum: number}) => number;
  var sumMeThisArray: (arr: number[]) => number;
  var nativeMap: (arr: number[], callback: (x: number) => number) => number[];
  var runJsFunction: () => void;
  var getDateObject: () => {
    day: number;
    month: number;
    year: number;
    now: number;
    hello: string;
  };
  var getInfinityObject: () => Record<string, any>;
}

export default function App() {
  const task1 = () => {
    console.log(answerToTheUltimateQuestionOfLifeTheUniverseAndEverything);
  };

  const task2 = () => {
    console.log(isWednesday);
  };

  const task3 = () => {
    console.log(workshopsName);
  };

  const task4 = () => {
    console.log(myAwesomeArray);
  };

  const task5 = () => {
    console.log(giveMeFive());
  };

  const task6 = () => {
    console.log(sumMeThis(4, 5));
  };

  const task7 = () => {
    console.log(divideMeThis(10, 5));

    try {
      divideMeThis(10, 0);
    } catch (e) {
      console.error(e);
    }
  };

  const task8 = () => {
    console.log(reverseMeThis('JSI workshops'));
  };

  const task9 = () => {
    console.log(sumMeThisObject({firstNum: 4, lastNum: 5}));
  };

  const task10 = () => {
    console.log(sumMeThisArray([1, 2, 3, 4, 5]));
  };

  const task11 = () => {
    const result = nativeMap([1, 2, 3, 4, 5], (x: number) => x * x);
    console.log(result);
  };

  const task12 = () => {
    runJsFunction();
  };

  const task13 = () => {
    const date = getDateObject();
    console.log(date);
    console.log(date.day, date.month, date.year);
    console.log(date.now);
    console.log(date.hello);
    console.log('------------------');
    date.day = 5;
    date.month = 12;
    date.year = 2025;
    console.log(date.day, date.month, date.year);
    console.log('------------------');
  };

  const task14 = () => {
    const infinityObject = getInfinityObject();
    console.log(infinityObject.a);
    console.log(infinityObject.wgwrw);
    console.log(infinityObject.jboqo345vj);
    infinityObject.x = 0;
    infinityObject.x = 0;
    console.log(infinityObject.ojbob);
  };

  const simpleObject = {};
  const task15 = () => {
    NativeJSIWorkshopsModule.task15(simpleObject);
    console.log(simpleObject);
  };

  return (
    <View style={styles.container}>
      <Button title="task1" onPress={task1} />
      <Button title="task2" onPress={task2} />
      <Button title="task3" onPress={task3} />
      <Button title="task4" onPress={task4} />
      <Button title="task5" onPress={task5} />
      <Button title="task6" onPress={task6} />
      <Button title="task7" onPress={task7} />
      <Button title="task8" onPress={task8} />
      <Button title="task9" onPress={task9} />
      <Button title="task10" onPress={task10} />
      <Button title="task11" onPress={task11} />
      <Button title="task12" onPress={task12} />
      <Button title="task13" onPress={task13} />
      <Button title="task14" onPress={task14} />
      <Button title="task15" onPress={task15} />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
