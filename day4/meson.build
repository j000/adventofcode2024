fs = import('fs')

day4input = fs.copyfile('input', 'input')

day4exe = executable('day4',
  'day4.cpp',
  )

run_target('day4_run',
  command: [day4exe, day4input],
  )

day4bexe = executable('day4b',
  'day4b.cpp',
  )

run_target('day4b_run',
  command: [day4bexe, day4input],
  )

# vim: set et ts=2 sw=2:
