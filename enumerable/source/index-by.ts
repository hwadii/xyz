import { ConditionalKeys, DefaultRecord } from "..";

export function indexBy<
  T,
  K extends ConditionalKeys<T, string | number | symbol>
>(list: T[], index: K): DefaultRecord<T> {
  return Object.fromEntries(list.map((elem) => [elem[index], elem]));
}
