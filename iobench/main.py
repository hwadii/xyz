from multiprocessing import Pool
from hashlib import sha1

NR_THREADS = 16


class Bench:
    def __init__(self, mask, grid):
        self._mask = mask
        self._grid = grid

    @property
    def mask(self):
        return self._mask

    @property
    def grid(self):
        return self._grid

    def word(self):
        word = [
            self.grid[i][j] if self.mask[i][j] == " " else ""
            for i in range(len(self.mask))
            for j in range(len(self.mask[i]))
        ]
        return "".join(word)


class BenchFactory:
    @classmethod
    def create_benches(cls, mask, grid, nr_threads=4):
        in_len = len(grid)
        assert nr_threads <= in_len, "in_len is smaller than nr_threads"
        pool_size = in_len // nr_threads

        def compute_bounds(thread_nr):
            start_pos = thread_nr * pool_size
            end_pos = start_pos + pool_size
            return slice(start_pos, end_pos)

        return [
            Bench(
                mask[compute_bounds(thread_nr)],
                grid[compute_bounds(thread_nr)]
            )
            for thread_nr in range(nr_threads)
        ]

    @classmethod
    def verify(cls, out: str, ref: str):
        return sha1(ref.encode()).digest() == sha1(out.encode()).digest()


if __name__ == '__main__':
    with open("./mask.txt", "r") as mask:
        mask_f = mask.read().splitlines()

    with open("./letters.txt", "r") as letters:
        letters_f = letters.read().splitlines()

    with open("./ref.txt", "r") as ref:
        ref_f = ref.read()

    benches = BenchFactory.create_benches(
        mask_f,
        letters_f, nr_threads=NR_THREADS
    )

    def do_word(b: Bench):
        return b.word()

    with Pool(processes=NR_THREADS) as pool:
        output = "".join(pool.map(do_word, benches))

    print(BenchFactory.verify(output, ref_f))
