ARG VERSION=5.7.40
ARG ENABLE_DEBUG_LOG=false
FROM mysql/mysql-server:${VERSION}

LABEL maintainer="ogenes.yi@gmail.com"

# 复制时区配置
ENV TZ=Asia/Shanghai
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# 默认配置
COPY my.cnf /etc/my.cnf
COPY docker.cnf /etc/mysql/conf.d/
COPY debug.cnf /etc/mysql/conf.d/
RUN chmod 644 /etc/my.cnf /etc/mysql/conf.d/*.cnf

RUN if $ENABLE_DEBUG_LOG; then \
    echo "DEBUG is enabled."; \
else \
    echo "DEBUG is false. Deleting /etc/mysql/conf.d/debug.cnf"; \
    rm /etc/mysql/conf.d/debug.cnf; \
fi

