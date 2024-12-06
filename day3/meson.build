fs = import('fs')

day3input = fs.copyfile('input', 'input')

day3exe = executable('day3',
  'day3.cpp',
  )

run_target('day3_run',
  command: [day3exe, day3input],
  )

day3bexe = executable('day3b',
  'day3b.cpp',
  )

run_target('day3b_run',
  command: [day3bexe, day3input],
  )

# vim: set et ts=2 sw=2:
