### 图书馆读者表

CREATE TABLE `reader` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL DEFAULT '' COMMENT '用户姓名',
  `gender` TINYINT NOT NULL DEFAULT 1 COMMENT '用户性别，1-男，2-女',
  `phone_number` VARCHAR(20) NOT NULL DEFAULT '' COMMENT '电话号码',
  PRIMARY KEY (`id`),
  UNIQUE INDEX `idx_phone_number` (`phone_number`) COMMENT '电话号码唯一索引'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='图书馆读者表';

###图书馆书籍表
CREATE TABLE book (
no INT UNSIGNED NOT NULL AUTO_INCREMENT,
name VARCHAR(255) NOT NULL COMMENT'书籍名',
author VARCHAR(255) NOT NULL COMMENT'作者',
category VARCHAR(100) COMMENT'分类',
publisher VARCHAR(255) COMMENT'出版社',
publish_date DATE COMMENT '出版时间',
price DECIMAL(10, 2) COMMENT '价格',
number INT COMMENT'数量',
PRIMARY KEY (no),
UNIQUE KEY unique_no (no)  COMMENT '书籍编号唯一索引'
) ENGINE=InnoDB DEFAULT CHARSET=gbk;

###读者借书表
CREATE TABLE BorrowingRecords (
borrowingid INT UNSIGNED NOT NULL AUTO_INCREMENT,
readerid INT NOT NULL COMMENT'读者id',
bookid INT NOT NULL COMMENT'书籍id',
quantity INT NOT NULL COMMENT'读者借书量', 
bookStorage INT NOT NULL COMMENT'书籍存储量',
PRIMARY KEY(borrowingid),
UNIQUE KEY unique_borrowingid (borrowingid)  
) ENGINE=InnoDB DEFAULT CHARSET=gbk;
