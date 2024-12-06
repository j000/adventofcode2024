fs = import('fs')

day1input = fs.copyfile('input', 'input')

day1exe = executable('day1',
  'day1.cpp',
  )

run_target('day1_run',
  command: [day1exe, day1input],
  depends: day1input,
  )

# vim: set et ts=2 sw=2:
