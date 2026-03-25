@echo off
setlocal enabledelayedexpansion
cls
color 0F
title Git 一键提交推送

:: ===================== 修复2：日志直接生成在【项目根目录】 =====================
set "PROJECT_PATH=D:\CPP project\cpp"
set "LOG_FILE=Git操作日志.txt"
set "SELF_FILE=%~nx0"
set "GITIGNORE_FILE=%PROJECT_PATH%\..\.gitignore"
set "COMMIT_MSG="
set "NOTES_MSG="
set "PULL_CHOICE="
set "DIFF_CHOICE="
set "PUSH_CHOICE="
set "UNDO_CHOICE="

:: ==============================================
:: 智能添加.gitignore，避免重复追加
:: ==============================================
if exist "%GITIGNORE_FILE%" (
    findstr /c:"%SELF_FILE%" "%GITIGNORE_FILE%" >nul
    if !errorlevel! equ 1 (
        echo.>> "%GITIGNORE_FILE%"
        echo %SELF_FILE%>> "%GITIGNORE_FILE%"
    )
    
    findstr /c:"Git操作日志.txt" "%GITIGNORE_FILE%" >nul
    if !errorlevel! equ 1 (
        echo Git操作日志.txt>> "%GITIGNORE_FILE%"
    )
) else (
    echo %SELF_FILE%> "%GITIGNORE_FILE%"
    echo Git操作日志.txt>> "%GITIGNORE_FILE%"
)

echo.
echo ======================================================
echo            Git 自动化提交推送脚本
echo ======================================================
echo.
echo 【脚本功能】
echo   1. 自动拉取远程最新代码 (可跳过)
echo   2. 可视化查看文件变更状态
echo   3. 一键调用 VS2022 查看代码差异
echo   4. 手动输入提交信息与注释
echo   5. 一键推送到 GitHub + Gitee 双仓库
echo   6. 自动记录操作日志到本地
echo.
echo 【操作流程】
echo   拉取代码 -^> 查看变更 -^> 提交代码 -^> 添加注释 -^> 推送代码
echo.
echo 【注意事项】
echo   1. 请确保已正确配置 Git 环境
echo   2. 请确保网络正常
echo   3. 提交信息不能为空
echo   4. 推送前会进行二次确认
echo.
echo ======================================================
echo 按任意键开始操作...
pause >nul
cls

echo.
echo ======================================================
echo [1/10] 正在校验项目环境 (git status)...
echo ======================================================
cd /d "%PROJECT_PATH%"
if !errorlevel! neq 0 (
    color 0C
    echo.
    echo [错误] 项目路径不存在！
    echo 请修改脚本顶部的 PROJECT_PATH 为正确路径
    echo.
    pause >nul
    exit /b 1
)

if not exist ".git" (
    color 0C
    echo.
    echo [错误] 当前文件夹不是 Git 仓库！
    echo.
    pause >nul
    exit /b 1
)
echo [√] 环境校验成功
echo.

echo ======================================================
echo [2/10] 查看当前文件修改状态 (git status)
echo ======================================================
echo ------------------------------------------------------
for /f "tokens=1,2" %%a in ('git status --short') do (
    if "%%a"=="M" (
        echo   [修改] 文件：%%b
    ) else if "%%a"=="A" (
        echo   [新增] 文件：%%b
    ) else if "%%a"=="D" (
        echo   [删除] 文件：%%b
    ) else if "%%a"=="??" (
        echo   [未跟踪] 文件：%%b
    ) else (
        echo   [其他] 变更：%%a %%b
    )
)
echo ------------------------------------------------------
echo.

echo ======================================================
echo [3/10] 拉取远程最新代码 (git pull origin master)
echo ======================================================
echo 说明：拉取远程最新代码可避免推送冲突
set "PULL_CHOICE="
set /p "PULL_CHOICE=请输入 [Y=拉取 N=跳过] 默认为Y："
if /i not "!PULL_CHOICE!"=="N" (
    echo 正在拉取代码...
    git pull origin master
    if !errorlevel! neq 0 (
        color 0C
        echo.
        echo [错误] 拉取失败！请查看上方 Git 输出的具体错误信息！
        echo.
        pause >nul
        exit /b 1
    )
    echo [√] 代码拉取完成
) else (
    echo [√] 已跳过拉取代码
)
echo.

echo ======================================================
echo [4/10] 检测文件变更 (git status)
echo ======================================================
git status --porcelain | findstr . >nul 2>&1
if !errorlevel! equ 1 (
    echo [√] 无任何文件修改，脚本自动退出
    echo.
    pause >nul
    exit /b 0
)
echo [√] 检测到文件变更
echo.

echo ======================================================
echo [5/10] 查看文件差异 (git difftool)
echo ======================================================
set "DIFF_CHOICE="
set /p "DIFF_CHOICE=请输入 [Y=查看 N=跳过] 默认为N："
if /i "!DIFF_CHOICE!"=="Y" (
    echo 正在启动 VS2022 差异工具...
    git difftool -t vs2022 >nul 2>&1
)
echo.

echo ======================================================
echo [6/10] 添加所有变更文件 (git add --all)
echo ======================================================
git add --all --ignore-errors >nul 2>&1
echo [√] 文件已加入暂存区
echo.

echo ======================================================
echo [7/10] 代码提交 (git commit)
echo ======================================================
echo 【提交信息规范示例】
echo   feat     新增功能（feature）            git commit -m "feat: 新增数组排序函数"
echo   fix      修复 bug / 问题              git commit -m "fix: 修复空指针异常"
echo   update   更新现有功能 / 依赖（非新增 / 修复）    git commit -m "update: 优化登录逻辑"
echo   docs     仅修改文档（README、注释等）        git commit -m "docs: 更新接口说明"
echo   style    代码格式调整（不影响逻辑，如空格、缩进）  git commit -m "style: 格式化代码缩进"
echo   refactor 重构代码              git commit -m "refactor: 重构用户类"
echo   test     测试代码              git commit -m "test: 补充单元测试用例"
echo   chore    配置修改              git commit -m "chore: 更新.gitignore"
echo   revert   撤销提交              git commit -m "revert: 撤销上次的feat提交"
echo.
set "COMMIT_MSG="
set /p "COMMIT_MSG=请输入本次提交信息："

if "!COMMIT_MSG!"=="" (
    color 0C
    echo.
    echo [错误] 提交信息不能为空！
    echo.
    pause >nul
    exit /b 1
)

git commit -m "!COMMIT_MSG!" >nul 2>&1
if !errorlevel! neq 0 (
    color 0C
    echo.
    echo [错误] 提交失败！
    echo.
    pause >nul
    exit /b 1
)
echo [√] 代码提交成功：!COMMIT_MSG!
echo.

echo ======================================================
echo [8/10] 后悔药选项 (git reset --soft HEAD^)
echo ======================================================
echo 说明：如果提交信息有误或不想提交，可以选择撤销
set "UNDO_CHOICE="
set /p "UNDO_CHOICE=是否撤销本次提交？[Y=撤销 N=继续] 默认为N："
if /i "!UNDO_CHOICE!"=="Y" (
    git reset --soft HEAD^ >nul 2>&1
    echo [√] 本次提交已撤销
    echo.
    pause >nul
    exit /b 0
)
echo [√] 已确认提交
echo.

echo ======================================================
echo [9/10] 添加注释 (git notes)
echo ======================================================
set "NOTES_MSG="
set /p "NOTES_MSG=请输入本次注释信息（可直接回车跳过）："

if not "!NOTES_MSG!"=="" (
    git notes add -f -m "!NOTES_MSG!" >nul 2>&1
    echo [√] 注释已添加/覆盖：!NOTES_MSG!
) else (
    echo [√] 未添加注释
)
echo.

echo ======================================================
echo [10/10] 推送确认 (git push)
echo ======================================================
echo 即将推送到 GitHub + Gitee 双仓库
set "PUSH_CHOICE="
set /p "PUSH_CHOICE=确认推送？[Y=确认 其他=取消] 默认为Y："
if /i not "!PUSH_CHOICE!"=="N" (
    echo 正在推送代码...
    :: ===================== 修复1：显示推送命令，不屏蔽输出，必执行 =====================
    git push
    set "PUSH_STATUS=成功"
) else (
    echo.
    echo [操作已取消] 未执行推送
    set "PUSH_STATUS=用户取消"
)

:: ===================== 修复1：移除强制闪退，保留提示 =====================
echo.
color 0A
echo ======================================================
echo                  全部操作执行完成！
echo ------------------------------------------------------
echo  提交信息：!COMMIT_MSG!
echo  注释信息：!NOTES_MSG!
echo  推送状态：!PUSH_STATUS!
echo ======================================================
echo.

:: ===================== 修复2：强制生成日志到根目录，必写入 =====================
echo ====================================================== >> "%LOG_FILE%"
echo 操作时间：%date% %time% >> "%LOG_FILE%"
echo ------------------------------------------------------ >> "%LOG_FILE%"
echo 提交信息：!COMMIT_MSG! >> "%LOG_FILE%"
echo 注释信息：!NOTES_MSG! >> "%LOG_FILE%"
echo 推送状态：!PUSH_STATUS! >> "%LOG_FILE%"
echo ====================================================== >> "%LOG_FILE%"
echo. >> "%LOG_FILE%"

echo [√] 操作日志已生成在：%cd%\Git操作日志.txt
echo.
echo 按任意键退出...
pause >nul
exit /b 0