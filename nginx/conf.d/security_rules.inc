# 禁止访问隐藏文件（如 .env, .git, .htaccess）
location ~ /\.(?!well-known).* {
    deny all;
    access_log /var/log/nginx/access.security.log;
    log_not_found off;
}

# 禁止访问常见敏感目录（Laravel、ThinkPHP、Node.js）
location ~ ^/(storage|bootstrap|runtime|extend|vendor|application|node_modules)/ {
    deny all;
    access_log /var/log/nginx/access.security.log;
    log_not_found off;
}

# 禁止访问配置文件和环境变量文件
location ~* \.(env|yml|yaml|ini|conf|config\.js|config\.json|lock|log)$ {
    deny all;
    access_log /var/log/nginx/access.security.log;
    log_not_found off;
}

# 禁止访问前端构建工具配置文件
location ~* /(webpack\.config\.js|vite\.config\.js|package\.json|tsconfig\.json|babel\.config\.js)/ {
    deny all;
    access_log /var/log/nginx/access.security.log;
    log_not_found off;
}
