import { pluck } from "./pluck";

export function pick<T extends unknown, K extends keyof T>(list: T[], ...keys: K[]): T[K] | Array<T[K]> | undefined {
  return pluck(list, ...keys)[0];
}
