const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();

    var input: [2000]u8 = undefined;
    _ = try stdin.readUntilDelimiter(&input, '\n');

    var found: bool = false;

    for (0..2000) |idx| {
        const c = input[idx];
        if (c == 'C' and input[idx + 1] == 'O' and input[idx + 2] == 'V') {
            found = true;
            break;
        }
        if (c == '\n') {
            break;
        }
    }

    const soln = if (found) "Veikur!" else "Ekki veikur!";
    try stdout.print("{s}\n", .{soln});
}
