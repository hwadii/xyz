export type DefaultRecord<T> = { [P in string | number | symbol]: T };

/**
 * @see https://github.com/sindresorhus/type-fest
 */
export type ConditionalKeys<Base, Condition> = NonNullable<
  { [K in keyof Base]: Base[K] extends Condition ? K : never; }[keyof Base]
>;
