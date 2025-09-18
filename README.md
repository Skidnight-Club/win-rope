<h1 align="center">Win-ROPE</h1>
<h3 align="center"> x64 Windows ROP Emporium translation</h3>
<p align="center">
  <img src="https://img.shields.io/badge/Windows--x86__64-supported-44CC11?style=flat-square"/>
  <img src="https://img.shields.io/badge/Windows--x86-unsupported-red?style=flat-square"/>
  <a href="https://mit-license.org/"/><img src="https://img.shields.io/github/license/Skidnight-Club/win-rope?style=flat-square&color=44CC11"/></a>
  <!--<img src="https://img.shields.io/github/actions/workflow/status/Skidnight-Club/win-rope/docker_build.yml?style=flat-square"/>-->
  <!--<img src="https://img.shields.io/github/actions/workflow/status/Skidnight-Club/win-rope/windows_unit_tests.yml?label=tests"/>-->
</p>
<br>

### Helpers
```bash
FILENAME="" objdump -dMintel "${FILENAME}" 2>&1 > "${FILENAME}.objdump"
FILENAME="" objdump -dMintel "${FILENAME}" 2>&1 | grep -E '[0-9]{16}\s<.*>:$'
FILENAME="" checksec --file="${FILENAME}"
```
